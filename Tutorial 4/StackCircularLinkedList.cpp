#include <iostream>

typedef struct NODE {
    int value;
    struct NODE *next;
} node;

typedef node* Position;

class Stack {
    public:
    Stack();
    void pop();
    void push(int value);
    int top();
    bool empty();

    private:
    Position end;
};

Stack::Stack() {
    end=new node;
    end->next=end;
}

void Stack::push(int value) {
    Position added=new node;
    added->value=value;
    added->next=end->next;
    end->next=added;
}

void Stack::pop() {
    Position temp=end->next;
    end->next=end->next->next;
}

int Stack::top() {
    return end->next->value;
}

bool Stack::empty() {
    if(end->next==end)
        return true;
    else 
        return false;
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    Stack q;
    q.push(a);
    q.push(b);
    q.push(c);
    q.push(d);
    printf("%d ",q.top());
    q.pop();
    printf("%d ",q.top());
    q.pop();
    printf("%d ",q.top());
    q.pop();
    printf("%d\n",q.top());
    q.pop();
    printf("%d\n",q.empty());
}