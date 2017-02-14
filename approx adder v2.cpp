//CHOO HONG YEE 25/12/2016
//v2 12/1/2017 -change the array into single dimensional
//v2.1 3/2/2017 - ED =2 is successfully done

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    //initialize original result from adder
    int ori_result[16] = {false,false,false,true,false,true,true,false,false,true,true,false,true,false,true,true};
    int ED;//get ED value
    int changed_result[16] = {false,false,false,true,false,true,true,false,false,true,true,false,true,false,true,true}; //array to allow changes
    int inverted_ori_result[16]={true,true,true,false,true,false,false,true,true,false,false,true,false,true,false,false};
    int inverted_changed_result[16]={true,true,true,false,true,false,false,true,true,false,false,true,false,true,false,false};//inverted array to reduce for loop in main function
    int count_of_outcome = 1 ; //display count of outcome

    ///////////////////////////////////////////////////////////////////////////////////
    //to create original file and display the correct data
    ofstream myfile;
    myfile.open("original_result.txt");
    myfile<<"original result\n";

    int j =0;
    for (int i = 0;i<16;i++) {
            if(i%2==0) {
                cout<<"C"<<j<<": "<<ori_result[i]; //print result for Carry
                myfile<<"C"<<j<<": "<<ori_result[i];
                continue;
            }
            else {
                cout<<"\tS"<<j<<": "<<ori_result[i]<<endl; //print result for Sum
                myfile<<"\tS"<<j<<": "<<ori_result[i]<<endl;
                j++; //does increment for display of carry and sum (C0,S0;C1,S1;...)
                continue;
            }
    }

    myfile.close();
    //////////////////////////////////////////////////////////////////////////

    cout<<endl<<"what is the value of ED: "; //prompt user input of ED value
    cin>>ED;

    //////////////////////////////////////////////////////////////////////////

    //create case for values of ED (so far done for ED =1 and 2)
    switch(ED) {
        case 1: //case for ED = 1
                myfile.open("new_result(ED=1).txt");
                myfile<<"Possible result for ED = "<<ED<<endl;
                for (int i = 0;i<16;i++) {
                    j=0;
                    myfile<<endl<<count_of_outcome<<")"<<endl;
                    cout<<endl<<count_of_outcome<<")"<<endl;
                    changed_result[i]=!changed_result[i]; //flipping every outcome
                    count_of_outcome++;
                    for (int i = 0;i<16;i++) { //print changed result
                        if(i%2==0) {
                            cout<<"C"<<j<<": "<<changed_result[i];
                            myfile<<"C"<<j<<": "<<changed_result[i];
                            changed_result[i]=ori_result[i];
                            continue;
                        }
                        else {
                            cout<<"\tS"<<j<<": "<<changed_result[i]<<endl;
                            myfile<<"\tS"<<j<<": "<<changed_result[i]<<endl;
                            changed_result[i]=ori_result[i];
                            j++;
                            continue;
                        }
                    }
                }
                myfile.close();
                break;
        case 2: //case for ED =2
                myfile.open("new_result(ED=2).txt");
                myfile<<"Possible result for ED = "<<ED<<endl;
                for (int i = 0;i<16;i++) {
                    changed_result[i]=!changed_result[i]; //flip outcome at C0 , will then increment to S0 as for loop completes
                    for (int k = i+1;k<16;k++) {
                        j=0;
                        myfile<<endl<<count_of_outcome<<")"<<endl;
                        cout<<endl<<count_of_outcome<<")"<<endl;
                        changed_result[k]=!changed_result[k]; //flip the next outcome after the first one in the previous for loop
                        count_of_outcome++;
                        for (int l = 0;l<16;l++) { //print changed result
                                if(l==i) { //check if the array has fixed outcome
                                    if(l%2==0) {
                                        cout<<"C"<<j<<": "<<changed_result[l];
                                        myfile<<"C"<<j<<": "<<changed_result[l];
                                        continue;
                                    }
                                    else {
                                        cout<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                        myfile<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                        j++;
                                        continue;
                                    }
                                }
                                else if(l%2==0) {
                                    cout<<"C"<<j<<": "<<changed_result[l];
                                    myfile<<"C"<<j<<": "<<changed_result[l];
                                    changed_result[l]=ori_result[l];
                                    continue;
                                }
                                else {
                                    cout<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                    myfile<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                    changed_result[l]=ori_result[l];
                                    j++;
                                    continue;
                                }
                        }
                    }
                    changed_result[i]=ori_result[i];
                }
                myfile.close();
                break;
        case 3: //case for ED =3
                myfile.open("new_result(ED=3).txt");
                myfile<<"Possible result for ED = "<<ED<<endl;
                for (int i = 0;i<16;i++) {
                    changed_result[i]=!changed_result[i];
                    for (int k = i+1;k<16;k++) {
                        changed_result[k]=!changed_result[k];
                        for (int m =k+1;m<16;m++) {
                            j=0;
                            myfile<<endl<<count_of_outcome<<")"<<endl;
                            cout<<endl<<count_of_outcome<<")"<<endl;
                            changed_result[m]=!changed_result[m];
                            count_of_outcome++;
                            for (int l = 0;l<16;l++) { //print changed result
                                    if(l==i) {
                                        if(l%2==0) {
                                            cout<<"C"<<j<<": "<<changed_result[l];
                                            myfile<<"C"<<j<<": "<<changed_result[l];
                                            continue;
                                        }
                                        else {
                                            cout<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                            myfile<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                            j++;
                                            continue;
                                        }
                                    }
                                    else if(l==k) {
                                        if(l%2==0) {
                                            cout<<"C"<<j<<": "<<changed_result[l];
                                            myfile<<"C"<<j<<": "<<changed_result[l];
                                            continue;
                                        }
                                        else {
                                            cout<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                            myfile<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                            j++;
                                            continue;
                                        }
                                    }
                                    else if(l%2==0) {
                                        cout<<"C"<<j<<": "<<changed_result[l];
                                        myfile<<"C"<<j<<": "<<changed_result[l];
                                        changed_result[l]=ori_result[l];
                                        continue;
                                    }
                                    else {
                                        cout<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                        myfile<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                        changed_result[l]=ori_result[l];
                                        j++;
                                        continue;
                                    }
                            }
                        }
                        changed_result[k]=ori_result[k];
                    }
                    changed_result[i]=ori_result[i];
                }
                myfile.close();
                break;
        case 4:
                myfile.open("new_result(ED=4).txt");
                myfile<<"Possible result for ED = "<<ED<<endl;
                for (int i = 0;i<16;i++) {
                    changed_result[i]=!changed_result[i];
                    for (int k = i+1;k<16;k++) {
                        changed_result[k]=!changed_result[k];
                        for (int m =k+1;m<16;m++) {
                            changed_result[m]=!changed_result[m];
                            for(int n =m+1;n<16;n++) {
                                j=0;
                                myfile<<endl<<count_of_outcome<<")"<<endl;
                                cout<<endl<<count_of_outcome<<")"<<endl;
                                changed_result[n]=!changed_result[n];
                                count_of_outcome++;
                                for (int l = 0;l<16;l++) { //print changed result
                                        if(l==i) {
                                            if(l%2==0) {
                                                cout<<"C"<<j<<": "<<changed_result[l];
                                                myfile<<"C"<<j<<": "<<changed_result[l];
                                                continue;
                                            }
                                            else {
                                                cout<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                myfile<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                j++;
                                                continue;
                                            }
                                        }
                                        else if(l==k) {
                                            if(l%2==0) {
                                                cout<<"C"<<j<<": "<<changed_result[l];
                                                myfile<<"C"<<j<<": "<<changed_result[l];
                                                continue;
                                            }
                                            else {
                                                cout<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                myfile<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                j++;
                                                continue;
                                            }
                                        }
                                        else if(l==m) {
                                            if(l%2==0) {
                                                cout<<"C"<<j<<": "<<changed_result[l];
                                                myfile<<"C"<<j<<": "<<changed_result[l];
                                                continue;
                                            }
                                            else {
                                                cout<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                myfile<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                j++;
                                                continue;
                                            }
                                        }
                                        else if(l%2==0) {
                                            cout<<"C"<<j<<": "<<changed_result[l];
                                            myfile<<"C"<<j<<": "<<changed_result[l];
                                            changed_result[l]=ori_result[l];
                                            continue;
                                        }
                                        else {
                                            cout<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                            myfile<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                            changed_result[l]=ori_result[l];
                                            j++;
                                            continue;
                                        }
                                }
                            }
                            changed_result[m]=ori_result[m];
                        }
                        changed_result[k]=ori_result[k];
                    }
                    changed_result[i]=ori_result[i];
                }
                myfile.close();
                break;
        case 5:
                myfile.open("new_result(ED=5).txt");
                myfile<<"Possible result for ED = "<<ED<<endl;
                for (int i = 0;i<16;i++) {
                    changed_result[i]=!changed_result[i];
                    for (int k = i+1;k<16;k++) {
                        changed_result[k]=!changed_result[k];
                        for (int m =k+1;m<16;m++) {
                            changed_result[m]=!changed_result[m];
                            for(int n =m+1;n<16;n++) {
                                changed_result[n]=!changed_result[n];
                                for(int o =n+1;o<16;o++) {
                                    j=0;
                                    myfile<<endl<<count_of_outcome<<")"<<endl;
                                    cout<<endl<<count_of_outcome<<")"<<endl;
                                    changed_result[o]=!changed_result[o];
                                    count_of_outcome++;
                                    for (int l = 0;l<16;l++) { //print changed result
                                            if(l==i) {
                                                if(l%2==0) {
                                                    cout<<"C"<<j<<": "<<changed_result[l];
                                                    myfile<<"C"<<j<<": "<<changed_result[l];
                                                    continue;
                                                }
                                                else {
                                                    cout<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                    myfile<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                    j++;
                                                    continue;
                                                }
                                            }
                                            else if(l==k) {
                                                if(l%2==0) {
                                                    cout<<"C"<<j<<": "<<changed_result[l];
                                                    myfile<<"C"<<j<<": "<<changed_result[l];
                                                    continue;
                                                }
                                                else {
                                                    cout<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                    myfile<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                    j++;
                                                    continue;
                                                }
                                            }
                                            else if(l==m) {
                                                if(l%2==0) {
                                                    cout<<"C"<<j<<": "<<changed_result[l];
                                                    myfile<<"C"<<j<<": "<<changed_result[l];
                                                    continue;
                                                }
                                                else {
                                                    cout<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                    myfile<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                    j++;
                                                    continue;
                                                }
                                            }
                                            else if(l==n) {
                                                if(l%2==0) {
                                                    cout<<"C"<<j<<": "<<changed_result[l];
                                                    myfile<<"C"<<j<<": "<<changed_result[l];
                                                    continue;
                                                }
                                                else {
                                                    cout<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                    myfile<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                    j++;
                                                    continue;
                                                }
                                            }
                                            else if(l%2==0) {
                                                cout<<"C"<<j<<": "<<changed_result[l];
                                                myfile<<"C"<<j<<": "<<changed_result[l];
                                                changed_result[l]=ori_result[l];
                                                continue;
                                            }
                                            else {
                                                cout<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                myfile<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                changed_result[l]=ori_result[l];
                                                j++;
                                                continue;
                                            }
                                    }
                                }
                                changed_result[n]=ori_result[n];
                            }
                            changed_result[m]=ori_result[m];
                        }
                        changed_result[k]=ori_result[k];
                    }
                    changed_result[i]=ori_result[i];
                }
                myfile.close();
                break;
        case 6:
                myfile.open("new_result(ED=6).txt");
                myfile<<"Possible result for ED = "<<ED<<endl;
                for (int i = 0;i<16;i++) {
                    changed_result[i]=!changed_result[i];
                    for (int k = i+1;k<16;k++) {
                        changed_result[k]=!changed_result[k];
                        for (int m =k+1;m<16;m++) {
                            changed_result[m]=!changed_result[m];
                            for(int n =m+1;n<16;n++) {
                                changed_result[n]=!changed_result[n];
                                for(int o =n+1;o<16;o++) {
                                    changed_result[o]=!changed_result[o];
                                    for(int p =o+1;p<16;p++) {
                                        j=0;
                                        myfile<<endl<<count_of_outcome<<")"<<endl;
                                        cout<<endl<<count_of_outcome<<")"<<endl;
                                        changed_result[p]=!changed_result[p];
                                        count_of_outcome++;
                                        for (int l = 0;l<16;l++) { //print changed result
                                                if(l==i) {
                                                    if(l%2==0) {
                                                        cout<<"C"<<j<<": "<<changed_result[l];
                                                        myfile<<"C"<<j<<": "<<changed_result[l];
                                                        continue;
                                                    }
                                                    else {
                                                        cout<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                        myfile<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                        j++;
                                                        continue;
                                                    }
                                                }
                                                else if(l==k) {
                                                    if(l%2==0) {
                                                        cout<<"C"<<j<<": "<<changed_result[l];
                                                        myfile<<"C"<<j<<": "<<changed_result[l];
                                                        continue;
                                                    }
                                                    else {
                                                        cout<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                        myfile<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                        j++;
                                                        continue;
                                                    }
                                                }
                                                else if(l==m) {
                                                    if(l%2==0) {
                                                        cout<<"C"<<j<<": "<<changed_result[l];
                                                        myfile<<"C"<<j<<": "<<changed_result[l];
                                                        continue;
                                                    }
                                                    else {
                                                        cout<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                        myfile<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                        j++;
                                                        continue;
                                                    }
                                                }
                                                else if(l==n) {
                                                    if(l%2==0) {
                                                        cout<<"C"<<j<<": "<<changed_result[l];
                                                        myfile<<"C"<<j<<": "<<changed_result[l];
                                                        continue;
                                                    }
                                                    else {
                                                        cout<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                        myfile<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                        j++;
                                                        continue;
                                                    }
                                                }
                                                else if(l==o) {
                                                    if(l%2==0) {
                                                        cout<<"C"<<j<<": "<<changed_result[l];
                                                        myfile<<"C"<<j<<": "<<changed_result[l];
                                                        continue;
                                                    }
                                                    else {
                                                        cout<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                        myfile<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                        j++;
                                                        continue;
                                                    }
                                                }
                                                else if(l%2==0) {
                                                    cout<<"C"<<j<<": "<<changed_result[l];
                                                    myfile<<"C"<<j<<": "<<changed_result[l];
                                                    changed_result[l]=ori_result[l];
                                                    continue;
                                                }
                                                else {
                                                    cout<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                    myfile<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                    changed_result[l]=ori_result[l];
                                                    j++;
                                                    continue;
                                                }
                                        }
                                    }
                                    changed_result[o]=ori_result[o];
                                }
                                changed_result[n]=ori_result[n];
                            }
                            changed_result[m]=ori_result[m];
                        }
                        changed_result[k]=ori_result[k];
                    }
                    changed_result[i]=ori_result[i];
                }
                myfile.close();
                break;
        case 7:
                myfile.open("new_result(ED=7).txt");
                myfile<<"Possible result for ED = "<<ED<<endl;
                for (int i = 0;i<16;i++) {
                    changed_result[i]=!changed_result[i];
                    for (int k = i+1;k<16;k++) {
                        changed_result[k]=!changed_result[k];
                        for (int m =k+1;m<16;m++) {
                            changed_result[m]=!changed_result[m];
                            for(int n =m+1;n<16;n++) {
                                changed_result[n]=!changed_result[n];
                                for(int o =n+1;o<16;o++) {
                                    changed_result[o]=!changed_result[o];
                                    for(int p =o+1;p<16;p++) {
                                        changed_result[p]=!changed_result[p];
                                        for(int q =p+1;q<16;q++) {
                                            j=0;
                                            myfile<<endl<<count_of_outcome<<")"<<endl;
                                            cout<<endl<<count_of_outcome<<")"<<endl;
                                            changed_result[q]=!changed_result[q];
                                            count_of_outcome++;
                                            for (int l = 0;l<16;l++) { //print changed result
                                                    if(l==i) {
                                                        if(l%2==0) {
                                                            cout<<"C"<<j<<": "<<changed_result[l];
                                                            myfile<<"C"<<j<<": "<<changed_result[l];
                                                            continue;
                                                        }
                                                        else {
                                                            cout<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                            myfile<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                            j++;
                                                            continue;
                                                        }
                                                    }
                                                    else if(l==k) {
                                                        if(l%2==0) {
                                                            cout<<"C"<<j<<": "<<changed_result[l];
                                                            myfile<<"C"<<j<<": "<<changed_result[l];
                                                            continue;
                                                        }
                                                        else {
                                                            cout<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                            myfile<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                            j++;
                                                            continue;
                                                        }
                                                    }
                                                    else if(l==m) {
                                                        if(l%2==0) {
                                                            cout<<"C"<<j<<": "<<changed_result[l];
                                                            myfile<<"C"<<j<<": "<<changed_result[l];
                                                            continue;
                                                        }
                                                        else {
                                                            cout<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                            myfile<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                            j++;
                                                            continue;
                                                        }
                                                    }
                                                    else if(l==n) {
                                                        if(l%2==0) {
                                                            cout<<"C"<<j<<": "<<changed_result[l];
                                                            myfile<<"C"<<j<<": "<<changed_result[l];
                                                            continue;
                                                        }
                                                        else {
                                                            cout<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                            myfile<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                            j++;
                                                            continue;
                                                        }
                                                    }
                                                    else if(l==o) {
                                                        if(l%2==0) {
                                                            cout<<"C"<<j<<": "<<changed_result[l];
                                                            myfile<<"C"<<j<<": "<<changed_result[l];
                                                            continue;
                                                        }
                                                        else {
                                                            cout<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                            myfile<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                            j++;
                                                            continue;
                                                        }
                                                    }
                                                    else if(l==p) {
                                                        if(l%2==0) {
                                                            cout<<"C"<<j<<": "<<changed_result[l];
                                                            myfile<<"C"<<j<<": "<<changed_result[l];
                                                            continue;
                                                        }
                                                        else {
                                                            cout<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                            myfile<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                            j++;
                                                            continue;
                                                        }
                                                    }
                                                    else if(l%2==0) {
                                                        cout<<"C"<<j<<": "<<changed_result[l];
                                                        myfile<<"C"<<j<<": "<<changed_result[l];
                                                        changed_result[l]=ori_result[l];
                                                        continue;
                                                    }
                                                    else {
                                                        cout<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                        myfile<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                        changed_result[l]=ori_result[l];
                                                        j++;
                                                        continue;
                                                    }
                                            }
                                        }
                                        changed_result[p]=ori_result[p];
                                    }
                                    changed_result[o]=ori_result[o];
                                }
                                changed_result[n]=ori_result[n];
                            }
                            changed_result[m]=ori_result[m];
                        }
                        changed_result[k]=ori_result[k];
                    }
                    changed_result[i]=ori_result[i];
                }
                myfile.close();
                break;
        case 8:
                myfile.open("new_result(ED=8).txt");
                myfile<<"Possible result for ED = "<<ED<<endl;
                for (int i = 0;i<16;i++) {
                    changed_result[i]=!changed_result[i];
                    for (int k = i+1;k<16;k++) {
                        changed_result[k]=!changed_result[k];
                        for (int m =k+1;m<16;m++) {
                            changed_result[m]=!changed_result[m];
                            for(int n =m+1;n<16;n++) {
                                changed_result[n]=!changed_result[n];
                                for(int o =n+1;o<16;o++) {
                                    changed_result[o]=!changed_result[o];
                                    for(int p =o+1;p<16;p++) {
                                        changed_result[p]=!changed_result[p];
                                        for(int q =p+1;q<16;q++) {
                                            changed_result[q]=!changed_result[q];
                                            for(int r =q+1;r<16;r++) {
                                                j=0;
                                                myfile<<endl<<count_of_outcome<<")"<<endl;
                                                cout<<endl<<count_of_outcome<<")"<<endl;
                                                changed_result[r]=!changed_result[r];
                                                count_of_outcome++;
                                                for (int l = 0;l<16;l++) { //print changed result
                                                        if(l==i) {
                                                            if(l%2==0) {
                                                                cout<<"C"<<j<<": "<<changed_result[l];
                                                                myfile<<"C"<<j<<": "<<changed_result[l];
                                                                continue;
                                                            }
                                                            else {
                                                                cout<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                                myfile<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                                j++;
                                                                continue;
                                                            }
                                                        }
                                                        else if(l==k) {
                                                            if(l%2==0) {
                                                                cout<<"C"<<j<<": "<<changed_result[l];
                                                                myfile<<"C"<<j<<": "<<changed_result[l];
                                                                continue;
                                                            }
                                                            else {
                                                                cout<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                                myfile<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                                j++;
                                                                continue;
                                                            }
                                                        }
                                                        else if(l==m) {
                                                            if(l%2==0) {
                                                                cout<<"C"<<j<<": "<<changed_result[l];
                                                                myfile<<"C"<<j<<": "<<changed_result[l];
                                                                continue;
                                                            }
                                                            else {
                                                                cout<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                                myfile<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                                j++;
                                                                continue;
                                                            }
                                                        }
                                                        else if(l==n) {
                                                            if(l%2==0) {
                                                                cout<<"C"<<j<<": "<<changed_result[l];
                                                                myfile<<"C"<<j<<": "<<changed_result[l];
                                                                continue;
                                                            }
                                                            else {
                                                                cout<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                                myfile<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                                j++;
                                                                continue;
                                                            }
                                                        }
                                                        else if(l==o) {
                                                            if(l%2==0) {
                                                                cout<<"C"<<j<<": "<<changed_result[l];
                                                                myfile<<"C"<<j<<": "<<changed_result[l];
                                                                continue;
                                                            }
                                                            else {
                                                                cout<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                                myfile<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                                j++;
                                                                continue;
                                                            }
                                                        }
                                                        else if(l==p) {
                                                            if(l%2==0) {
                                                                cout<<"C"<<j<<": "<<changed_result[l];
                                                                myfile<<"C"<<j<<": "<<changed_result[l];
                                                                continue;
                                                            }
                                                            else {
                                                                cout<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                                myfile<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                                j++;
                                                                continue;
                                                            }
                                                        }
                                                        else if(l==q) {
                                                            if(l%2==0) {
                                                                cout<<"C"<<j<<": "<<changed_result[l];
                                                                myfile<<"C"<<j<<": "<<changed_result[l];
                                                                continue;
                                                            }
                                                            else {
                                                                cout<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                                myfile<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                                j++;
                                                                continue;
                                                            }
                                                        }
                                                        else if(l%2==0) {
                                                            cout<<"C"<<j<<": "<<changed_result[l];
                                                            myfile<<"C"<<j<<": "<<changed_result[l];
                                                            changed_result[l]=ori_result[l];
                                                            continue;
                                                        }
                                                        else {
                                                            cout<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                            myfile<<"\tS"<<j<<": "<<changed_result[l]<<endl;
                                                            changed_result[l]=ori_result[l];
                                                            j++;
                                                            continue;
                                                        }
                                                }
                                            }
                                            changed_result[q]=ori_result[q];
                                        }
                                        changed_result[p]=ori_result[p];
                                    }
                                    changed_result[o]=ori_result[o];
                                }
                                changed_result[n]=ori_result[n];
                            }
                            changed_result[m]=ori_result[m];
                        }
                        changed_result[k]=ori_result[k];
                    }
                    changed_result[i]=ori_result[i];
                }
                myfile.close();
                break;
        case 9: //case for ED =9
                myfile.open("new_result(ED=9).txt");
                myfile<<"Possible result for ED = "<<ED<<endl;
                for (int i = 0;i<16;i++) {
                    inverted_changed_result[i]=!inverted_changed_result[i];
                    for (int k = i+1;k<16;k++) {
                        inverted_changed_result[k]=!inverted_changed_result[k];
                        for (int m = k+1;m<16;m++) {
                            inverted_changed_result[m]=!inverted_changed_result[m];
                            for (int n = m+1;n<16;n++) {
                                inverted_changed_result[n]=!inverted_changed_result[n];
                                for (int o = n+1;o<16;o++) {
                                    inverted_changed_result[o]=!inverted_changed_result[o];
                                    for (int p = o+1;p<16;p++) {
                                        inverted_changed_result[p]=!inverted_changed_result[p];
                                        for (int q = p+1;q<16;q++) {
                                            j=0;
                                            myfile<<endl<<count_of_outcome<<")"<<endl;
                                            cout<<endl<<count_of_outcome<<")"<<endl;
                                            inverted_changed_result[q]=!inverted_changed_result[q];
                                            count_of_outcome++;
                                            for (int l = 0;l<16;l++) { //print changed result
                                                    if(l==i) {
                                                        if(l%2==0) {
                                                            cout<<"C"<<j<<": "<<inverted_changed_result[l];
                                                            myfile<<"C"<<j<<": "<<inverted_changed_result[l];
                                                            continue;
                                                        }
                                                        else {
                                                            cout<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                            myfile<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                            j++;
                                                            continue;
                                                        }
                                                    }
                                                    else if(l==k) {
                                                        if(l%2==0) {
                                                            cout<<"C"<<j<<": "<<inverted_changed_result[l];
                                                            myfile<<"C"<<j<<": "<<inverted_changed_result[l];
                                                            continue;
                                                        }
                                                        else {
                                                            cout<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                            myfile<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                            j++;
                                                            continue;
                                                        }
                                                    }
                                                    else if(l==m) {
                                                        if(l%2==0) {
                                                            cout<<"C"<<j<<": "<<inverted_changed_result[l];
                                                            myfile<<"C"<<j<<": "<<inverted_changed_result[l];
                                                            continue;
                                                        }
                                                        else {
                                                            cout<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                            myfile<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                            j++;
                                                            continue;
                                                        }
                                                    }
                                                    else if(l==n) {
                                                        if(l%2==0) {
                                                            cout<<"C"<<j<<": "<<inverted_changed_result[l];
                                                            myfile<<"C"<<j<<": "<<inverted_changed_result[l];
                                                            continue;
                                                        }
                                                        else {
                                                            cout<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                            myfile<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                            j++;
                                                            continue;
                                                        }
                                                    }
                                                    else if(l==o) {
                                                        if(l%2==0) {
                                                            cout<<"C"<<j<<": "<<inverted_changed_result[l];
                                                            myfile<<"C"<<j<<": "<<inverted_changed_result[l];
                                                            continue;
                                                        }
                                                        else {
                                                            cout<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                            myfile<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                            j++;
                                                            continue;
                                                        }
                                                    }
                                                    else if(l==p) {
                                                        if(l%2==0) {
                                                            cout<<"C"<<j<<": "<<inverted_changed_result[l];
                                                            myfile<<"C"<<j<<": "<<inverted_changed_result[l];
                                                            continue;
                                                        }
                                                        else {
                                                            cout<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                            myfile<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                            j++;
                                                            continue;
                                                        }
                                                    }
                                                    else if(l%2==0) {
                                                        cout<<"C"<<j<<": "<<inverted_changed_result[l];
                                                        myfile<<"C"<<j<<": "<<inverted_changed_result[l];
                                                        inverted_changed_result[l]=inverted_ori_result[l];
                                                        continue;
                                                    }
                                                    else {
                                                        cout<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                        myfile<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                        inverted_changed_result[l]=inverted_ori_result[l];
                                                        j++;
                                                        continue;
                                                    }
                                            }
                                        }
                                        inverted_changed_result[p]=inverted_ori_result[p];
                                    }
                                    inverted_changed_result[o]=inverted_ori_result[o];
                                }
                                inverted_changed_result[n]=inverted_ori_result[n];
                            }
                            inverted_changed_result[m]=inverted_ori_result[m];
                        }
                        inverted_changed_result[k]=inverted_ori_result[k];
                    }
                    inverted_changed_result[i]=inverted_ori_result[i];
                }
                myfile.close();
                break;
        case 10: //case for ED =10
                myfile.open("new_result(ED=10).txt");
                myfile<<"Possible result for ED = "<<ED<<endl;
                for (int i = 0;i<16;i++) {
                    inverted_changed_result[i]=!inverted_changed_result[i];
                    for (int k = i+1;k<16;k++) {
                        inverted_changed_result[k]=!inverted_changed_result[k];
                        for (int m = k+1;m<16;m++) {
                            inverted_changed_result[m]=!inverted_changed_result[m];
                            for (int n = m+1;n<16;n++) {
                                inverted_changed_result[n]=!inverted_changed_result[n];
                                for (int o = n+1;o<16;o++) {
                                    inverted_changed_result[o]=!inverted_changed_result[o];
                                    for (int p = o+1;p<16;p++) {
                                        j=0;
                                        myfile<<endl<<count_of_outcome<<")"<<endl;
                                        cout<<endl<<count_of_outcome<<")"<<endl;
                                        inverted_changed_result[p]=!inverted_changed_result[p];
                                        count_of_outcome++;
                                        for (int l = 0;l<16;l++) { //print changed result
                                                if(l==i) {
                                                    if(l%2==0) {
                                                        cout<<"C"<<j<<": "<<inverted_changed_result[l];
                                                        myfile<<"C"<<j<<": "<<inverted_changed_result[l];
                                                        continue;
                                                    }
                                                    else {
                                                        cout<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                        myfile<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                        j++;
                                                        continue;
                                                    }
                                                }
                                                else if(l==k) {
                                                    if(l%2==0) {
                                                        cout<<"C"<<j<<": "<<inverted_changed_result[l];
                                                        myfile<<"C"<<j<<": "<<inverted_changed_result[l];
                                                        continue;
                                                    }
                                                    else {
                                                        cout<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                        myfile<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                        j++;
                                                        continue;
                                                    }
                                                }
                                                else if(l==m) {
                                                    if(l%2==0) {
                                                        cout<<"C"<<j<<": "<<inverted_changed_result[l];
                                                        myfile<<"C"<<j<<": "<<inverted_changed_result[l];
                                                        continue;
                                                    }
                                                    else {
                                                        cout<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                        myfile<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                        j++;
                                                        continue;
                                                    }
                                                }
                                                else if(l==n) {
                                                    if(l%2==0) {
                                                        cout<<"C"<<j<<": "<<inverted_changed_result[l];
                                                        myfile<<"C"<<j<<": "<<inverted_changed_result[l];
                                                        continue;
                                                    }
                                                    else {
                                                        cout<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                        myfile<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                        j++;
                                                        continue;
                                                    }
                                                }
                                                else if(l==o) {
                                                    if(l%2==0) {
                                                        cout<<"C"<<j<<": "<<inverted_changed_result[l];
                                                        myfile<<"C"<<j<<": "<<inverted_changed_result[l];
                                                        continue;
                                                    }
                                                    else {
                                                        cout<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                        myfile<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                        j++;
                                                        continue;
                                                    }
                                                }
                                                else if(l%2==0) {
                                                    cout<<"C"<<j<<": "<<inverted_changed_result[l];
                                                    myfile<<"C"<<j<<": "<<inverted_changed_result[l];
                                                    inverted_changed_result[l]=inverted_ori_result[l];
                                                    continue;
                                                }
                                                else {
                                                    cout<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                    myfile<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                    inverted_changed_result[l]=inverted_ori_result[l];
                                                    j++;
                                                    continue;
                                                }
                                        }
                                    }
                                    inverted_changed_result[o]=inverted_ori_result[o];
                                }
                                inverted_changed_result[n]=inverted_ori_result[n];
                            }
                            inverted_changed_result[m]=inverted_ori_result[m];
                        }
                        inverted_changed_result[k]=inverted_ori_result[k];
                    }
                    inverted_changed_result[i]=inverted_ori_result[i];
                }
                myfile.close();
                break;
        case 11: //case for ED =11
                myfile.open("new_result(ED=11).txt");
                myfile<<"Possible result for ED = "<<ED<<endl;
                for (int i = 0;i<16;i++) {
                    inverted_changed_result[i]=!inverted_changed_result[i];
                    for (int k = i+1;k<16;k++) {
                        inverted_changed_result[k]=!inverted_changed_result[k];
                        for (int m = k+1;m<16;m++) {
                            inverted_changed_result[m]=!inverted_changed_result[m];
                            for (int n = m+1;n<16;n++) {
                                inverted_changed_result[n]=!inverted_changed_result[n];
                                for (int o = n+1;o<16;o++) {
                                    j=0;
                                    myfile<<endl<<count_of_outcome<<")"<<endl;
                                    cout<<endl<<count_of_outcome<<")"<<endl;
                                    inverted_changed_result[o]=!inverted_changed_result[o];
                                    count_of_outcome++;
                                    for (int l = 0;l<16;l++) { //print changed result
                                            if(l==i) {
                                                if(l%2==0) {
                                                    cout<<"C"<<j<<": "<<inverted_changed_result[l];
                                                    myfile<<"C"<<j<<": "<<inverted_changed_result[l];
                                                    continue;
                                                }
                                                else {
                                                    cout<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                    myfile<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                    j++;
                                                    continue;
                                                }
                                            }
                                            else if(l==k) {
                                                if(l%2==0) {
                                                    cout<<"C"<<j<<": "<<inverted_changed_result[l];
                                                    myfile<<"C"<<j<<": "<<inverted_changed_result[l];
                                                    continue;
                                                }
                                                else {
                                                    cout<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                    myfile<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                    j++;
                                                    continue;
                                                }
                                            }
                                            else if(l==m) {
                                                if(l%2==0) {
                                                    cout<<"C"<<j<<": "<<inverted_changed_result[l];
                                                    myfile<<"C"<<j<<": "<<inverted_changed_result[l];
                                                    continue;
                                                }
                                                else {
                                                    cout<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                    myfile<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                    j++;
                                                    continue;
                                                }
                                            }
                                            else if(l==n) {
                                                if(l%2==0) {
                                                    cout<<"C"<<j<<": "<<inverted_changed_result[l];
                                                    myfile<<"C"<<j<<": "<<inverted_changed_result[l];
                                                    continue;
                                                }
                                                else {
                                                    cout<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                    myfile<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                    j++;
                                                    continue;
                                                }
                                            }
                                            else if(l%2==0) {
                                                cout<<"C"<<j<<": "<<inverted_changed_result[l];
                                                myfile<<"C"<<j<<": "<<inverted_changed_result[l];
                                                inverted_changed_result[l]=inverted_ori_result[l];
                                                continue;
                                            }
                                            else {
                                                cout<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                myfile<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                inverted_changed_result[l]=inverted_ori_result[l];
                                                j++;
                                                continue;
                                            }
                                    }
                                }
                                inverted_changed_result[n]=inverted_ori_result[n];
                            }
                            inverted_changed_result[m]=inverted_ori_result[m];
                        }
                        inverted_changed_result[k]=inverted_ori_result[k];
                    }
                    inverted_changed_result[i]=inverted_ori_result[i];
                }
                myfile.close();
                break;
        case 12: //case for ED =12
                myfile.open("new_result(ED=12).txt");
                myfile<<"Possible result for ED = "<<ED<<endl;
                for (int i = 0;i<16;i++) {
                    inverted_changed_result[i]=!inverted_changed_result[i];
                    for (int k = i+1;k<16;k++) {
                        inverted_changed_result[k]=!inverted_changed_result[k];
                        for (int m = k+1;m<16;m++) {
                            inverted_changed_result[m]=!inverted_changed_result[m];
                            for (int n = m+1;n<16;n++) {
                                j=0;
                                myfile<<endl<<count_of_outcome<<")"<<endl;
                                cout<<endl<<count_of_outcome<<")"<<endl;
                                inverted_changed_result[n]=!inverted_changed_result[n];
                                count_of_outcome++;
                                for (int l = 0;l<16;l++) { //print changed result
                                        if(l==i) {
                                            if(l%2==0) {
                                                cout<<"C"<<j<<": "<<inverted_changed_result[l];
                                                myfile<<"C"<<j<<": "<<inverted_changed_result[l];
                                                continue;
                                            }
                                            else {
                                                cout<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                myfile<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                j++;
                                                continue;
                                            }
                                        }
                                        else if(l==k) {
                                            if(l%2==0) {
                                                cout<<"C"<<j<<": "<<inverted_changed_result[l];
                                                myfile<<"C"<<j<<": "<<inverted_changed_result[l];
                                                continue;
                                            }
                                            else {
                                                cout<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                myfile<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                j++;
                                                continue;
                                            }
                                        }
                                        else if(l==m) {
                                            if(l%2==0) {
                                                cout<<"C"<<j<<": "<<inverted_changed_result[l];
                                                myfile<<"C"<<j<<": "<<inverted_changed_result[l];
                                                continue;
                                            }
                                            else {
                                                cout<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                myfile<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                                j++;
                                                continue;
                                            }
                                        }
                                        else if(l%2==0) {
                                            cout<<"C"<<j<<": "<<inverted_changed_result[l];
                                            myfile<<"C"<<j<<": "<<inverted_changed_result[l];
                                            inverted_changed_result[l]=inverted_ori_result[l];
                                            continue;
                                        }
                                        else {
                                            cout<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                            myfile<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                            inverted_changed_result[l]=inverted_ori_result[l];
                                            j++;
                                            continue;
                                        }
                                }
                            }
                            inverted_changed_result[m]=inverted_ori_result[m];
                        }
                        inverted_changed_result[k]=inverted_ori_result[k];
                    }
                    inverted_changed_result[i]=inverted_ori_result[i];
                }
                myfile.close();
                break;
        case 13: //case for ED =13
                myfile.open("new_result(ED=13).txt");
                myfile<<"Possible result for ED = "<<ED<<endl;
                for (int i = 0;i<16;i++) {
                    inverted_changed_result[i]=!inverted_changed_result[i];
                    for (int k = i+1;k<16;k++) {
                        inverted_changed_result[k]=!inverted_changed_result[k];
                        for (int m = k+1;m<16;m++) {
                            j=0;
                            myfile<<endl<<count_of_outcome<<")"<<endl;
                            cout<<endl<<count_of_outcome<<")"<<endl;
                            inverted_changed_result[m]=!inverted_changed_result[m];
                            count_of_outcome++;
                            for (int l = 0;l<16;l++) { //print changed result
                                    if(l==i) {
                                        if(l%2==0) {
                                            cout<<"C"<<j<<": "<<inverted_changed_result[l];
                                            myfile<<"C"<<j<<": "<<inverted_changed_result[l];
                                            continue;
                                        }
                                        else {
                                            cout<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                            myfile<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                            j++;
                                            continue;
                                        }
                                    }
                                    else if(l==k) {
                                        if(l%2==0) {
                                            cout<<"C"<<j<<": "<<inverted_changed_result[l];
                                            myfile<<"C"<<j<<": "<<inverted_changed_result[l];
                                            continue;
                                        }
                                        else {
                                            cout<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                            myfile<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                            j++;
                                            continue;
                                        }
                                    }
                                    else if(l%2==0) {
                                        cout<<"C"<<j<<": "<<inverted_changed_result[l];
                                        myfile<<"C"<<j<<": "<<inverted_changed_result[l];
                                        inverted_changed_result[l]=inverted_ori_result[l];
                                        continue;
                                    }
                                    else {
                                        cout<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                        myfile<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                        inverted_changed_result[l]=inverted_ori_result[l];
                                        j++;
                                        continue;
                                    }
                            }
                        }
                        inverted_changed_result[k]=inverted_ori_result[k];
                    }
                    inverted_changed_result[i]=inverted_ori_result[i];
                }
                myfile.close();
                break;
        case 14: //case for ED =14
                myfile.open("new_result(ED=14).txt");
                myfile<<"Possible result for ED = "<<ED<<endl;
                for (int i = 0;i<16;i++) {
                    inverted_changed_result[i]=!inverted_changed_result[i];
                    for (int k = i+1;k<16;k++) {
                        j=0;
                        myfile<<endl<<count_of_outcome<<")"<<endl;
                        cout<<endl<<count_of_outcome<<")"<<endl;
                        inverted_changed_result[k]=!inverted_changed_result[k];
                        count_of_outcome++;
                        for (int l = 0;l<16;l++) { //print changed result
                                if(l==i) {
                                    if(l%2==0) {
                                        cout<<"C"<<j<<": "<<inverted_changed_result[l];
                                        myfile<<"C"<<j<<": "<<inverted_changed_result[l];
                                        continue;
                                    }
                                    else {
                                        cout<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                        myfile<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                        j++;
                                        continue;
                                    }
                                }
                                else if(l%2==0) {
                                    cout<<"C"<<j<<": "<<inverted_changed_result[l];
                                    myfile<<"C"<<j<<": "<<inverted_changed_result[l];
                                    inverted_changed_result[l]=inverted_ori_result[l];
                                    continue;
                                }
                                else {
                                    cout<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                    myfile<<"\tS"<<j<<": "<<inverted_changed_result[l]<<endl;
                                    inverted_changed_result[l]=inverted_ori_result[l];
                                    j++;
                                    continue;
                                }
                        }
                    }
                    inverted_changed_result[i]=inverted_ori_result[i];
                }
                myfile.close();
                break;
        case 15: //case for ED = 15
                myfile.open("new_result(ED=15).txt");
                myfile<<"Possible result for ED = "<<ED<<endl;
                for (int i = 0;i<16;i++) {
                    j=0;
                    myfile<<endl<<count_of_outcome<<")"<<endl;
                    cout<<endl<<count_of_outcome<<")"<<endl;
                    inverted_changed_result[i]=!inverted_changed_result[i]; //flipping every outcome
                    count_of_outcome++;
                    for (int i = 0;i<16;i++) { //print changed result
                        if(i%2==0) {
                            cout<<"C"<<j<<": "<<inverted_changed_result[i];
                            myfile<<"C"<<j<<": "<<inverted_changed_result[i];
                            inverted_changed_result[i]=inverted_ori_result[i];
                            continue;
                        }
                        else {
                            cout<<"\tS"<<j<<": "<<inverted_changed_result[i]<<endl;
                            myfile<<"\tS"<<j<<": "<<inverted_changed_result[i]<<endl;
                            inverted_changed_result[i]=inverted_ori_result[i];
                            j++;
                            continue;
                        }
                    }
                }
                myfile.close();
                break;
        case 16: //case for ED = 15
                myfile.open("new_result(ED=16).txt");
                myfile<<"Possible result for ED = "<<ED<<endl;
                j=0;
                myfile<<endl<<count_of_outcome<<")"<<endl;
                cout<<endl<<count_of_outcome<<")"<<endl;
                count_of_outcome++;
                for (int i = 0;i<16;i++) { //print changed result
                    if(i%2==0) {
                        cout<<"C"<<j<<": "<<inverted_changed_result[i];
                        myfile<<"C"<<j<<": "<<inverted_changed_result[i];
                        continue;
                    }
                    else {
                        cout<<"\tS"<<j<<": "<<inverted_changed_result[i]<<endl;
                        myfile<<"\tS"<<j<<": "<<inverted_changed_result[i]<<endl;
                        j++;
                        continue;
                    }
                }
                myfile.close();
                break;

    }
    //////////////////////////////////////////////////////////////////////////

    return 0;
}
