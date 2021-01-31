//not for direct use just take the parts and use
// using namespace std;
// // struct node
// //     {
// //         int data;
// //         struct node*next;
// //     };
// // template<class gen>
// // class stack{
// //     protected:
// //     public:
// //     virtual void push(gen ele)=0;
// //     virtual void pop()=0;
// //     virtual gen& top()=0;
// //     virtual bool is_empty()=0;
// //     virtual int size()=0;
// // };
// template<class T>
// class switchbox:
// {
// private:
// struct node
//     {
//         int data;
//         struct node*next;
//     };
//     struct node*head;
// public:
//     switchbox();
//     ~switchbox();
//     void push(T ele);
//     void pop();
//     T& top();
//     bool is_empty();
//     int size();
//     friend bool check(int* connection,int NoP);
// };
// template<class T>
// void switchbox<T>::push(T ele){
//     struct node *newnode;
//     newnode = new node;
//     newnode->data = ele;
//     newnode->next = head;
//     head = newnode;
//     // cout<<"\nPushed "<<newnode->data<<"\n"; to beprinted in a file
// }
// template<class T>
// void switchbox<T>::pop(){
//     if(head==NULL)
//         cout<<"\nUnderflow\n\n";
//     else{
//         struct node *temp;
//         temp = head;
//         head = head->next;
//         free(temp);
//     }
// }
// template<class T>
// T& switchbox<T>::top(){
//     if(head==NULL)
//         cout<<"\nUnderflow\n\n";
//     else
//         return head->data;
// }

// template<class T>
// bool switchbox<T>::is_empty(){
//     if(head==NULL)
//         return true;
//     else
//         return false;    
// }

//  bool check(int* connection,int NoP)
// {
//     switchbox<int>* s = new switchbox<int>;
//     for (int i = 0; i < NoP; i++)
//     {
//         if(!s->is_empty())
//             if (connection[i] == connection[s->top()])
//                 s->pop();
//             else
//                 s->push(i);
//         else
//             s->push(i);
//     }

//     if (s->is_empty())
//     {
//         cout<<"Switch box is routable\n";
//         return true;
//     }

//     cout<<"Switch box is not routable\n";
//     return false;
// }


// int* getnet(int NoP)
// {
//     int* Net=new int[NoP];
//     for(int i=1;i<NoP+1;i++)
//     {
//         cout<<"\nPlease enter the Pin corresponding to "<<i<<" :";
//         cin>>Net[i];
//     }
//     return(Net);
// }
// int main()
// {
//     int p;
//     cout<<"\nEnter the no of pins";
//     cin>>p;
//     check(getnet(p),p);
    
// }

#include <iostream>

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
};

template<class T>
void Stack<T>::push(T a){
    struct node *newnode;
    newnode = new node;
    newnode->data = a;
    newnode->next = head;
    head = newnode;
    cout<<"\nPushed "<<newnode->data<<"\n";
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
        cout<<"\nPoped "<<n<<"\n";
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


bool check(int net[], int n){
    Stack<int>* s = new Stack<int>;

    for (int i = 0; i < n; i++)
    {
        if(!s->empty())
            if (net[i] == net[s->top()])
                s->pop();
            else
                s->push(i);
        else
            s->push(i);
    }

    if (s->empty())
    {
        cout<<"Switch box is routable\n";
        return true;
    }

    cout<<"Switch box is not routable\n";
    return false;
}

int main(){
    cout<<"Enter the number of pins: ";
    int n;
    cin>>n;

    int* net = new int[n];

    cout<<"enter the nets for pin 1 through "<<n<<endl;
    for (int i = 0; i < n; i++)
        cin>>net[i];

    cout<<check(net,n);
}
//modular
//files
//excdptions

