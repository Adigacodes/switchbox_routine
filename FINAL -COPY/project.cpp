#include<iostream>
#include<fstream>
#include <sstream>
#include "class_defination.h"
using namespace std;

void checkBox(string, fileHandler&);

int main(int argc, char** argv){

    try {
        if (argc > 1) {
            fileHandler f;
            int choice;
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
                    checkBox(name, f);
                    break;
                case 2:
                    f.detailedResult();
                    break;
                case 3:
                    f.viewAllRecordOf(name);
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

void checkBox(string name, fileHandler& f){
    int n;
    cout<<"Enter the number of pins: ";
    try{
        cin>>n;
        if (n%2!=0)
        {
            throw (n);
        }else{
            sbox<int> b1(n); //MAKING AN OBJECT OF INT TYPE OF SBOX CLASS
            cin>>b1;
            if(b1.check()==1){
                cout<<"ROUTABLE\n";
            }
            else{
                cout<<"NOT ROUTABLE\n";
            }

            f.addRecord(name, b1);
        }    
    }
    catch(int n){
        cout<<"Switch box should have even number of pins........\n\n";
    }
}