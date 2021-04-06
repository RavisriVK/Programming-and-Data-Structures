#include<iostream>
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
        void push(Object& element) {
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

bool isBalanced(char *exp, int n)
{
    Stack<char> s;
    for(int i=0; i<n; i++) {
        char bracket=exp[i];
        if(bracket=='(' || bracket=='[' || bracket=='{') {
            s.push(bracket);
        } else if(bracket==')') {
            if(s.empty() || s.top()!='(')
                return false;
            else 
                s.pop();
        } else if(bracket==']') {
            if(s.empty() || s.top()!='[')
                return false;
            else 
                s.pop();
        } else if(bracket=='}') {
            if(s.empty() || s.top()!='{')
                return false;
            else 
                s.pop();
        }
    }
    return s.empty();
}
int main()
{
    char exp[100];
    cin>>exp;
    int n=strlen(exp);
    if(isBalanced(exp, n))
        cout<<"Balanced\n";
    else 
        cout<<"Not Balanced\n";
}