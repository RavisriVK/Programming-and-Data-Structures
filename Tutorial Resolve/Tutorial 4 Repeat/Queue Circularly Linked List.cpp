#include<iostream>
using namespace std;

template<typename Object>
class Queue {
    private:
        struct node {
            Object element;
            node* next;
            node(Object val=Object(), node* nxt=nullptr): element(val), next(nxt) {}
        };
    public:
        Queue() {
            back=new node();
            back->next=back;
        }
        void push(Object& element) {
            node* newNode=new node(element, back->next);
            back->next=newNode;
            back=newNode;
        }
        void pop() {
            if(!empty()) {
                node* toDelete=back->next->next;
                back->next->next=toDelete->next;
                if(back==toDelete)
                    back=back->next;
                delete toDelete;
            }
        }
        Object front() {
            if(!empty())
                return back->next->next->element;
            else
                return Object();
        }
        Object rear() {
            if(!empty())
                return back->element;
            else 
                return Object();
        }
        bool empty() {
            return back==back->next;
        }
        void print() {
            for(node* i=back->next->next; i!=back->next; i=i->next)
                cout<<i->element<<" ";
            cout<<"#\n";
        }
    private:
        node* back;
};

int main()
{
    Queue<int> q;
    int n;
    cin>>n;
    int op;
    for(int i=0; i<n; i++) {
        cin>>op;
        if(op==1) {
            int in;
            cin>>in;
            q.push(in);
        } else if(op==2) {
            q.pop();
        } else if(op==3) {
            q.print();
        }
    }
}