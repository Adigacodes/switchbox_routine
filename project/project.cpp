#include<iostream>
#include<fstream>
#include <sstream>
#include "class_defination.h"
using namespace std;

int main(){
    cout<<"Enter the number of pins: ";
    int n;
    cin>>n;
    sbox<int> b1(n);
    cin>>b1;
    if(b1.check()==1)
        cout<<"Routable";
    else
        cout<<"Not Routable";
    
}