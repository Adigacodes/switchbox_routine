//tried exception but didnt fit right , files still solving on that appened prob wen done ill edit ,not much for inclusion of files just cout->fout

#include<iostream>
#include<fstream>
using namespace std;

class myexception:public exception
{
private:
    /* data */
public:
    string invalidpin()
    {
        return "\nInvalid Pin number\n";
    }
    string Underflow()
    {
        return "\nStack underflow cant pop anymore\n";
    }
    bool is_empty()
    {
        return true;
    }
};

template<class T>
class stack
{
protected:
    struct node
    {
        T data;
        struct node *next;
    };
    struct node*top;
    
public:
    stack(){
        top=NULL;
    }
    void push(T val);
    void pop();
    T peek();
    bool empty();
    void display();
};
template<class T>
void stack<T>::push(T val){
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=top;
    top=newnode;
}
template<class T>
void stack<T>::pop(){
    struct node*temp;
    temp=top;
    top=top->next;
    delete(temp);
}
template<class T>
T stack<T>::peek(){
    if(top==NULL)
    {
       cout<<"UNDERFLOW\n";
    }
    else
    {
        return top->data;
    }
    
}
template<class T>
bool stack<T>::empty(){
    if(top==NULL)
    {
       return true;
    }
}
template<class T>
void stack<T>::display(){
    if(top==NULL)
    {
    cout<<"THE STACK IS -------------  EMPTY\n";

    }
    else
    {
        struct node *temp;
    temp=top;
    cout<<"THE STACK IS --------------\t";
    while(temp!=NULL)
    {
        cout<<"<="<<(temp->data)+1;
        temp=temp->next;
    }
    cout<<endl;
    }
    
}
template<class T>
class sbox:public stack<T>
{
private:

public:
    sbox(){
    }
    string checkbox(int p,int net[]){
    sbox<T>* s = new sbox<T>;
    cout<<"\nTHE STACK BEFORE PROCESSING\n";
    s->display();
    for (int i = 0; i < p; i++)
    {
        cout<<"PROCESSING PIN :"<<i+1<<endl;
        if(!s->empty()){
            cout<<"STACK IS NOT EMPTY PUSHING PIN :"<<i<<"FOR PROCESSING"<<endl;
            if (net[i] == net[s->peek()]){
                s->push(i);
                s->display();
                cout<<"SINCE THE PRECEDING PIN IS CONNECTED WITH THE PUSHED PIN THEY FORM A ROUTABLE NET"<<endl;
                cout<<"HENCE BOTH ARE POPPED FROM THE PROCESSING STACK\n";
                s->pop();
                s->pop();
            }
            else{
                cout<<"SINCE THE PRECEDING PIN IS NOT CONNECTED WITH THE PUSHED PIN THEY DONT FORM A ROUTABLE NET\nHENCE THE STACK IS UNDISTURBED FOR FUTHER PROCESSING"<<endl;
                s->push(i);
                s->display();

            }
        }
           
        else{
            cout<<"STACK IS EMPTY PUSHING PIN :"<<i<<endl;
            s->push(i);
            s->display();
        }
    }

    if (s->empty())
    {
        
        cout<<"END OF PROCESSING ------------------------------------------------------\nSWITCHBOX IS ROUTABLE";
        return "Success";
        
    }
    else
    {
        
        cout<<"END OF PROCESSING ------------------------------------------------------\nSWITCHBOX IS NOT ROUTABLE";
        return "Failed";
    }
    
    
    }
};
int main()
{
    cout<<"\nEnter the no of Pins in the switchbox......";int p;
    cin>>p;
    int* net = new int[p];
    cout<<"\nENTER THE PINS AND THEIR CONNECTIONS ACCORDINGLY......\n";
    for(int i=0;i<p;i++)
    {
        cout<<"ENTER THE PIN CORRESPONDING TO "<<i+1<<".....";cin>>net[i];
        
        
    }
    sbox<int> b1;
    cout<<b1.checkbox(p,net);


}
