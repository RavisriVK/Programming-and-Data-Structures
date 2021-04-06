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

template<typename Object>
class Queue {
    public:
        void push(Object element) {
            rear.push(element);
        }
        void pop() {
            if(front.empty()) {
                while(!rear.empty()) {
                    front.push(rear.top());
                    rear.pop();
                }
            }
            front.pop();
        }
        Object top() {
            if(front.empty()) {
                while(!rear.empty()) {
                    front.push(rear.top());
                    rear.pop();
                }
            }
            return front.top();
        }
        Object bottom() {
            if(rear.empty()) {
                while(!front.empty()) {
                    rear.push(front.top());
                    front.pop();
                }
            }
            return rear.top();
        }
    private:
        Stack<Object> rear;
        Stack<Object> front;
};

int main() {
    Queue<int> q;
    q.push(1);
    q.push(2);
    printf("%d\n",q.top());
    q.pop();
    q.push(3);
    q.push(4);
    printf("%d\n",q.top());
    q.pop();
    printf("%d\n",q.top());
    q.pop();
    printf("%d\n",q.bottom());
    q.pop();
}
