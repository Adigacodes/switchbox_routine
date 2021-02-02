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
        string res;
    public:
        sbox(int k);
        template<class X>
        friend istream& operator>>(istream &input, sbox<X> &c);

        T* get_net();
        int get_n();
        string get_result();
        int check();
};

template<class T>
class fileHandler{
    private:
        string box = "box.txt";
        string record = "prev.csv";
    public:
        void addRecord(string, sbox<T>&);
        void detailedResult();
        void viewAllRecordOf(string);
};