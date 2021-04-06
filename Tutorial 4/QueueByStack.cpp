#include<iostream>
#include<stack>
using namespace std;

class Queue {
    public:
        void push(int value);
        void pop();
        int front();
        int back();
    private:
        stack <int> s1;
        stack <int> s2;
};

void Queue::push(int value) {
    s1.push(value);
}

void Queue::pop() {
    if(s2.empty()) {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
    s2.pop();
}

int Queue::front() {
    if(s2.empty()) {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
    return s2.top();
}

int Queue::back() {
    if(s1.empty()) {
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    return s1.top();
}

int main() {
    Queue q;
    q.push(1);
    q.push(2);
    printf("%d\n",q.front());
    q.pop();
    q.push(3);
    q.push(4);
    printf("%d\n",q.front());
    q.pop();
    printf("%d\n",q.front());
    q.pop();
    printf("%d\n",q.back());
    q.pop();
}

