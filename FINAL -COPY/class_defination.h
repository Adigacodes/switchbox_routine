#include<iostream>
#include<fstream>
#include <vector>

#include "class_declaration.h"
using namespace std;


template<class T>
void Stack<T>::push(T a){
    struct node *newnode;
    newnode = new node;
    newnode->data = a;
    newnode->next = head;
    head = newnode;
    // cout<<"\nPushed "<<newnode->data<<"\n";
}

template<class T>
T Stack<T>::pop(){
    if(head==NULL)
        cout<<"\nUnderflow\n\n";
    else{
        struct node *temp;
        T n;
        temp = head;
        n = head->data;
        head = head->next;
        free(temp);
        // cout<<"\nPoped "<<n<<"\n";
        return n;
    }
}

template<class T>
T Stack<T>::top(){
    if(head==NULL)
        cout<<"\nUnderflow\n\n";
    else
        return head->data;
}

template<class T>
bool Stack<T>::empty(){
    if(head==NULL)
        return true;
    else
        return false;    
}

template<class T>
void Stack<T>::display(ofstream& fout){
    if (head==NULL)
    {
        fout<<"\nTHE STACK IS -------------  EMPTY\n";
    }
    else
    {
        struct node *temp;
        temp=head;
    fout<<"THE STACK IS --------------\t";
    while(temp!=NULL)
    {
        fout<<"<="<<(temp->data)+1;
        temp=temp->next;
    }
    fout<<endl;
    }
}
// template<class T>        ANOTHER WAY OF DISPLAY 
// void Stack<T>::display(){
//     ofstream fpout;
//     fpout.open("box.txt",ios::app);

//     if(top==NULL)
//     {
//     // cout<<"THE STACK IS -------------  EMPTY\n";
//     fpout<<"\nTHE STACK IS -------------  EMPTY\n";


//     }
//     else
//     {
//         struct node *temp;
//     temp=top;
//     // cout<<"THE STACK IS --------------\t";
//     fpout<<"THE STACK IS --------------\t";

//     while(temp!=NULL)
//     {
//         // cout<<"<="<<(temp->data)+1;
//         fpout<<"<="<<(temp->data)+1;

//         temp=temp->next;
//     }
//     cout<<endl;
//     }
//     fpout.close();
// }

// Class 2;

template<class T>
sbox<T>::sbox(int k){
    n= k;
    net = new int[n];
}

template<class T>
T* sbox<T>::get_net(){
    return this->net;
}

template<class T>
int sbox<T>::get_n(){
    return this->n;
}

template<class T>
string sbox<T>::get_result(){
    return this->res;
}

template<class T>
int sbox<T>::check(){
    Stack<int>* s = new Stack<int>;

    ofstream fout;
    fout.open("box.txt",ios::out);
    fout<<"\nTHE STACK BEFORE PROCESSING\n";

    s->display(fout);

    for (int i = 0; i < n; i++)
    {
        fout<<"PROCESSING PIN: "<<i+1<<endl;
        if(!s->empty()){
            fout<<"STACK IS NOT EMPTY PUSHING PIN: "<<i+1<<" FOR PROCESSING"<<endl;
            if (net[i] == net[s->top()]){
                s->push(i);
                s->display(fout);
                fout
                    <<"SINCE THE PRECEDING PIN IS CONNECTED WITH THE PUSHED PIN THEY FORM A ROUTABLE NET\n"
                    <<"HENCE BOTH ARE POPPED FROM THE PROCESSING STACK\n";
                s->pop();
                s->pop();
            }
            else{
                fout
                    <<"SINCE THE PRECEDING PIN IS NOT CONNECTED WITH THE PUSHED PIN THEY DONT FORM A ROUTABLE NET"
                    <<"\nHENCE THE STACK IS UNDISTURBED FOR FUTHER PROCESSING"<<endl;
                s->push(i);
                s->display(fout);

            }
        }
        
        else{
            fout<<"STACK IS EMPTY PUSHING PIN :"<<i+1<<endl;
            s->push(i);
            s->display(fout);
        }
    }

    if (s->empty())
    {
        
        fout
            <<"END OF PROCESSING ------------------------------------------------------"
            <<"\nSWITCHBOX IS ROUTABLE";
        fout.close();
        res = "Success";
        return 1;
        
    }
    else
    {
        fout
            <<"END OF PROCESSING ------------------------------------------------------"
            <<"\nSWITCHBOX IS NOT ROUTABLE";
        fout.close();
        res = "Failure";
        return 0;
    }   
}

template<class T>
istream& operator >>(istream &input, sbox<T> &c)
{
    cout<<"\nENTER THE PINS AND THEIR CONNECTIONS ACCORDINGLY\n";
    for(int i=0;i<c.n;i++)
    {
        cout<<"ENTER THE PIN CORRESPONDING TO "<<i+1<<" ";
        input>>c.net[i];
    }
    return input;
}


// Class 3

void fileHandler::addRecord(string name, sbox<int>& b1){
        ifstream fin(record, ifstream::in);
        // ifstream fin;           ANOTHER WAY TO OPEN FILE
        // fin.open(record,ios::in);

        if (fin.fail()) 
        {
            ofstream fo;
            fo.open(record,ios::out);

            fo<<"NAME ,NO OF PINS ,NET_CONNECTIONS ,STATUS\n";
            fo.close();
        }
        else
            fin.close();
        
        ofstream fo;
        fo.open(record,ios::app);

        fo<<name<<","<< b1.get_n() << ",";

        int * net = b1.get_net();
        for (int i = 0; i < b1.get_n(); i++)
        {
            fo<<net[i]<<" ";
        }

        fo<<","<<b1.get_result()<<"\n";
        fo.close();
}

void fileHandler::detailedResult(){
    ifstream MyFile(box);
    string oneLine;
    cout<<"\n\n-------------------------PROCESSING DATA------------------\n";
    while (getline (MyFile, oneLine)) {
        cout << oneLine;
        cout<<"\n";
    }
    cout<<"\n\n----------------------END OF PROCESSING--------------------\n";
    cout<<endl;
    MyFile.close();
}

void fileHandler::viewAllRecordOf(string username){
    cout<<"\n\n-------------------------RECORDS-------------------------\n";
    
    ifstream MyFile(record);

    vector<string> g1; 
    string line, word, temp; 

    getline(MyFile, line);

    stringstream s(line);

    while(getline(s, word, ',')) { 
        g1.push_back(word); 
    } 

    cout<<g1[0]<<"\t"<<g1[1]<<"\t"<<g1[2]<<"\t"<<g1[3]<<"\n";

    bool anyHistory = false;

    while (!MyFile.eof()){ 
        g1.clear();

        getline(MyFile, line);

        stringstream s(line);

        while(getline(s, word, ',')) { 
            g1.push_back(word); 
        } 

        if (g1[0] == username) {
            anyHistory = true;
            cout<<g1[0]<<"\t"<<g1[1]<<"\t\t"<<g1[2]<<"\t"<<g1[3]<<endl;
        }
    }

    if (!anyHistory)
    {
        cout<<"\n----------------------NO PREVIOUS RECORDS--------------------\n";
    }
    
    cout<<endl;
    MyFile.close();
}