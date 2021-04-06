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
                dummy->next=toDelete->next;
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

bool isPalindrome(char* exp, int n)
{
    Stack<char> s;
    for(int i=0; i<n/2; i++)
        s.push(exp[i]);
    for(int i=(n+1)/2; i<n; i++) 
        if(s.top()!=exp[i])
            return false;
        else
            s.pop();
    return true;
}

int main()
{
    char exp[100];
    cin>>exp;
    int n=strlen(exp);
    if(isPalindrome(exp, n))
        cout<<"Palindrome\n";
    else 
        cout<<"Not Palindrome\n";
}