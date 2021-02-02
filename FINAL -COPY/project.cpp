#include<iostream>
#include<fstream>
#include <sstream>
#include "class_defination.h"
using namespace std;

template<class T>
void checkBox(string, fileHandler<T>&);

int main(int argc, char** argv){

    try {
        if (argc > 1) {
            fileHandler<char> fChar;
            fileHandler<int> fInt;
            int choice;
            char tp;
            string name = argv[1];
            cout
                <<"-------------------------WELCOME "<<name<<", TO SWITCH BOX ROUTINE-------------------------\n";
            while (1)
            {
                cout
                    <<"1. WANT TO CHECK IF YOUR BOX IS ROUTABLE\n"
                    <<"2. VIEW THE PROCESSING DATA FOR ANALYSIS\n"
                    <<"3. WANNA CHECK YOUR PROCESSED CREDENTIALS\n"
                    <<"0. EXIT THE TOOL\n";
                cin>>choice;
                switch(choice)
                {
                case 0:
                cout<<"\nEXITING THE TOOL --------------------------------------VISIT US AGAIN\n";
                    exit(0);
                    break;
                
                case 1:
                    cout<<"\nPress 'c' to use CHAR as convension or press i to use INT: ";
                    cin>>tp;
                    if (tp=='c'||tp=='C')
                    {
                        checkBox(name, fChar);
                    }
                    else
                    {
                        checkBox(name, fInt);
                    }
                    
                    break;
                case 2:
                    if (tp=='c'||tp=='C')
                    {
                        fChar.detailedResult();
                    }
                    else
                    {
                        fInt.detailedResult();
                    }
                    break;
                case 3:
                     if (tp=='c'||tp=='C')
                    {
                        fChar.viewAllRecordOf(name);
                    }
                    else
                    {
                        fInt.viewAllRecordOf(name);
                    }
                    break;

                default:
                    break;
                }
            }
        } else {
            throw (argc);
        }
    }
    catch (int myNum) {
        cout << "PLS PROVIDE US WITH YOUR NAME IN THE BELOW FORMAT.\n";
        cout << "PLS ENTER AS DEMONSTRATED \"./a.out <NAME>\"\n";
    }
}


template<class T>
void checkBox(string name, fileHandler<T>& f){
    int n;
    cout<<"Enter the number of pins: ";
    try{
        cin>>n;
        if (n%2!=0)
        {
            throw (n);
        }else{
            sbox<T> b1(n); //MAKING AN OBJECT OF INT TYPE OF SBOX CLASS
            cin>>b1;
            if(b1.check()==1){
                cout<<"ROUTABLE\n\n";
            }
            else{
                cout<<"NOT ROUTABLE\n\n";
            }

            f.addRecord(name, b1);
        }    
    }
    catch(int n){
        cout<<"Switch box should have even number of pins........\n\n";
    }
}