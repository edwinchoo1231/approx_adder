//CHOO HONG YEE 25/12/2016
//v2 12/1/2017 -change the array into single dimensional

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    //initialize original result from adder
    int ori_result[16] = {false,false,false,true,false,true,true,false,false,true,true,false,true,false,true,true};
    int ED;//get ED value
    int changed_result[16] = {false,false,false,true,false,true,true,false,false,true,true,false,true,false,true,true}; //array to allow changes
    int count_of_outcome = 1 ; //display count of outcome

    ///////////////////////////////////////////////////////////////////////////////////
    //to create original file and display the correct data
    ofstream myfile;
    myfile.open("original_result1.txt");
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
     //create text file to store new data
    myfile.open("new_result.txt");
    myfile<<"Possible result for ED = "<<ED<<endl;

    //create case for values of ED (so far done for ED =1)
    switch(ED) {
        case 1: //case for ED = 1
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
                break;
        case 2: //case for ED =2 (still not complete)
                for (int i = 0;i<16;i++) {
                    j=0;
                    myfile<<endl<<count_of_outcome<<")"<<endl;
                    cout<<endl<<count_of_outcome<<")"<<endl;
                    changed_result[i]=!changed_result[i];
                    changed_result[i+1]=!changed_result[i+1];
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
                break;
    }
    myfile.close();
    //////////////////////////////////////////////////////////////////////////

    return 0;
}
