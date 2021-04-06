#include <iostream>

typedef struct NODE {
    int value;
    struct NODE *next;
} node;

typedef node* Position;

class Queue {
    public:
    Queue();
    void pop();
    void push(int value);
    int front();
    int back();
    bool empty();

    private:
    Position last;
};

Queue::Queue() {
    last=new node;
    last->next=last;
}

void Queue::push(int value) {
    Position added=new node;
    added->value=value;
    added->next=last->next;
    last->next=added;
    last=last->next;
}

void Queue::pop() {
    if(last->next!=last) {
        if(last->next->next==last) {
            last=last->next;
            delete last->next;
            last->next=last;
        } else {
            Position first=last->next->next;
            last->next->next=first->next;
            delete first;
        }
    }
}

int Queue::front() {
    return last->next->next->value;
}

int Queue::back() {
    return last->value;
}

bool Queue::empty() {
    if(last->next==last)
        return true;
    else 
        return false;
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    Queue q;
    q.push(a);
    q.push(b);
    q.push(c);
    q.push(d);
    printf("%d ",q.front());
    q.pop();
    printf("%d ",q.front());
    q.pop();
    printf("%d ",q.front());
    q.pop();
    printf("%d\n",q.front());
    q.pop();
    printf("%d\n",q.empty());
}