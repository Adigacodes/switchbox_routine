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
                    <<"1-To check a routing box\n"
                    <<"2-To print the detailed result\n"
                    <<"3-Print all history\n"
                    <<"0-exit\n";
                cin>>choice;
                switch(choice)
                {
                case 0:
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
        cout << "Name Field is Missing\n";
        cout << "Please run in this format \"./a.out <NAME>\"\n";
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
            sbox<int> b1(n);
            cin>>b1;
            if(b1.check()==1){
                cout<<"Routable\n";
            }
            else{
                cout<<"Not Routable\n";
            }

            f.addRecord(name, b1);
        }    
    }
    catch(int n){
        cout<<"Switch box shold have even number of pins\n\n";
    }
}