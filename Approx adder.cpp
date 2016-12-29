//CHOO HONG YEE 25/12/2016

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    //initialize original result from adder
    int ori_result[8][2] = { {false,false},{false,true},{false,true},{true,false},{false,true},{true,false},{true,false},{true,true}};
    int ED;//get ED value
    int changed_result[8][2] = { {false,false},{false,true},{false,true},{true,false},{false,true},{true,false},{true,false},{true,true}}; //array to allow changes
    int count_of_outcome = 1 ; //display count of outcome

    ///////////////////////////////////////////////////////////////////////////////////
    //to create original file and display the correct data
    ofstream myfile;
    myfile.open("original_result.txt");
    myfile<<"original result\n";

    for (int i = 0;i<8;i++) {
        for (int j = 0;j<1;){
            cout<<"C"<<i<<": "<<ori_result[i][j];
            myfile<<"C"<<i<<": "<<ori_result[i][j];
            j++;
            cout<<"\tS"<<i<<": "<<ori_result[i][j]<<endl;
            myfile<<"\tS"<<i<<": "<<ori_result[i][j]<<endl;
        }
    }

    myfile.close();
    /////////////////////////////////////////////////////////////////

    cout<<"what is the value of ED: "; //prompt user input of ED value
    cin>>ED;

    /////////////////////////////////////////////////////////////////
    //create text file to store new data
    myfile.open("new_result.txt");
    myfile<<"Possible result for ED = "<<ED<<endl;

    //create case for values of ED (so far done for ED =1)
    switch(ED) {
        case 1:
            for (int i = 0;i<8;i++) {
                for (int j = 0;j<1;){
                    myfile<<endl<<count_of_outcome<<")"<<endl;
                    cout<<endl<<count_of_outcome<<")"<<endl;
                    changed_result[i][j]=!changed_result[i][j];
                    count_of_outcome++;
                        for (int i = 0;i<8;i++) {
                            for (int j = 0;j<1;){
                                cout<<"C"<<i<<": "<<changed_result[i][j];
                                myfile<<"C"<<i<<": "<<changed_result[i][j];
                                changed_result[i][j]=ori_result[i][j];

                                j++;//doing the increment here so that the display would shows an indent of spaces to the right

                                cout<<"\tS"<<i<<": "<<changed_result[i][j]<<endl;
                                myfile<<"\tS"<<i<<": "<<changed_result[i][j]<<endl;
                                changed_result[i][j]=ori_result[i][j];
                                }
                        }
                    j++;
                    myfile<<endl<<count_of_outcome<<")"<<endl;
                    cout<<endl<<count_of_outcome<<")"<<endl;
                    changed_result[i][j]=!changed_result[i][j];
                    count_of_outcome++;
                        for (int i = 0;i<8;i++) {
                            for (int j = 0;j<1;){
                                cout<<"C"<<i<<": "<<changed_result[i][j];
                                myfile<<"C"<<i<<": "<<changed_result[i][j];
                                changed_result[i][j]=ori_result[i][j];

                                j++;

                                cout<<"\tS"<<i<<": "<<changed_result[i][j]<<endl;
                                myfile<<"\tS"<<i<<": "<<changed_result[i][j]<<endl;
                                changed_result[i][j]=ori_result[i][j];
                                }

                        }
                }
        }
    }

    myfile.close();
    //////////////////////////////////////////////////////////////////////////
    return 0;
}
