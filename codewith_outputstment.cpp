//check files display part
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
        void display(); 
};

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
void Stack<T>::display(){
    ofstream dout;
    dout.open("box.txt",ios::app);
    struct node *temp;
    temp=head;
    dout<<"THE STACK IS --------------\t";
    while(temp!=NULL)
    {
        dout<<"<="<<temp->data;
        temp=temp->next;
    }
    cout<<endl;
    dout.close();
}
string check(int net[], int n){
    Stack<int>* s = new Stack<int>;
    ofstream fout;
    fout.open("box.txt",ios::out);
    fout<<"\nTHE STACK BEFORE PROCESSING\n";
    s->display();
    for (int i = 0; i < n; i++)
    {
        fout<<"PROCESSING PIN :"<<i<<endl;
        if(!s->empty()){
            fout<<"STACK IS NOT EMPTY PUSHING PIN :"<<i<<"FOR PROCESSING"<<endl;
            if (net[i] == net[s->top()]){
                s->push(i);
                s->display();
                fout<<"SINCE THE PRECEDING PIN IS CONNECTED WITH THE PUSHED PIN THEY FORM A ROUTABLE NET"<<endl;
                fout<<"HENCE BOTH ARE POPPED FROM THE PROCESSING STACK\n";
                s->pop();
                s->pop();
            }
            else{
                fout<<"SINCE THE PRECEDING PIN IS NOT CONNECTED WITH THE PUSHED PIN THEY DONT FORM A ROUTABLE NET\nHENCE THE STACK IS UNDISTURBED FOR FUTHER PROCESSING"<<endl;
                s->push(i);
                s->display();

            }
        }
           
        else{
            fout<<"STACK IS EMPTY PUSHING PIN :"<<i<<endl;
            s->push(i);
            s->display();
        }
    }

    if (s->empty())
    {
        
        fout<<"END OF PROCESSING ------------------------------------------------------\nSWITCHBOX IS ROUTABLE";
        fout.close();
        return "Success";
        
    }
    else
    {
        
        fout<<"END OF PROCESSING ------------------------------------------------------\nSWITCHBOX IS NOT ROUTABLE";
        fout.close();
        return "Failed";
    }
    
    
}

int main()
{
cout<<"Enter the number of pins: ";
    int n;
    cin>>n;

    int* net = new int[n];

    cout<<"enter the nets for pin 1 through "<<n<<endl;
    for (int i = 0; i < n; i++){
        cin>>net[i];
    }
       

    cout<<check(net,n);
}
