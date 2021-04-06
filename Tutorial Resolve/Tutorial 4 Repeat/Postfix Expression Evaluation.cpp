#include<iostream>
#include<string>
using namespace std;

template<typename Object>
class Stack {
    private:
        struct node {
            Object element;
            node* next;
            node(Object val=Object(), node* nxt=nullptr): element(val), next(nxt) {}
        };
    public:
        Stack() {
            dummy=new node();
            dummy->next=dummy;
        }
        void push(Object element) {
            node* newNode=new node(element, dummy->next);
            dummy->next=newNode;
        }
        void pop() {
            if(!empty()) {
                node* toDelete=dummy->next;
                dummy->next=dummy->next->next;
                delete toDelete;
            }
        }
        Object top() {
            if(!empty())
                return dummy->next->element;
            else
                return Object();
        }
        bool empty() {
            return dummy==dummy->next;
        }
    private:
        node* dummy;
};

int main()
{
    Stack<int> s;

    int delimiter=' ';
    string in;

    while(delimiter!='\n')
    {
        cin>>in;
        if(isnumber(in.back())) {
            s.push(stoi(in));
        } else {
            int in2=s.top();
            s.pop();
            int in1=s.top();
            s.pop();
            if(in.compare("+")==0) {
                s.push(in1+in2);
            } else if(in.compare("-")==0) {
                s.push(in1-in2);
            } else if(in.compare("*")==0) {
                s.push(in1*in2);
            } else if(in.compare("/")==0) {
                s.push(in1/in2);
            } else if(in.compare("%")==0) {
                s.push(in1%in2);
            }
        }

        while((delimiter=getc(stdin))==' ')
            ;
        ungetc(delimiter,stdin);
    }

    cout<<(s.top())<<"\n";
    s.pop();
}