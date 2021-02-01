#include<iostream>
#include<fstream>
using namespace std;

template<class T>
class Stack{
    private:
        struct node{
            T data;
            struct node * next;
        };
        struct node * head;
    public:
        Stack(){
            head = NULL;
        }
        void push(T);
        T pop();
        T top();
        bool empty();       
        void display(ofstream&); 
};

template<class T>
class sbox:public Stack<T>
{
    private:
        int n;
        T* net;
    public:
        sbox(int k);
        template<class X>
        friend istream& operator>>(istream &input, sbox<X> &c);
        int check();
};
