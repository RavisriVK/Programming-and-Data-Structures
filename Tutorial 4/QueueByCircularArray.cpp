#include <iostream>
using namespace std;

#define ARRAY_SIZE 4

class Queue {
    public:
    Queue();
    void pop();
    void push(int value);
    int front();
    int back();
    bool empty();
    bool full();

    private:
    int *array;
    int start;
    int end;
};

Queue::Queue() {
    array=new int[ARRAY_SIZE];
    start=-1;
    end=-1;
}

void Queue::push(int value) {
    if(start==end && start==-1) {
        start=0; end=0;
        array[end]=value;
    } else if((end+1)%ARRAY_SIZE!=start) {
        end=(end+1)%ARRAY_SIZE;
        array[end]=value;
    }
}

void Queue::pop() {
    if(start!=end) {
        start=(start+1)%ARRAY_SIZE;
    } else {
        start=-1;
        end=-1;
    }
}

int Queue::front() {
    return array[start];
}

int Queue::back() {
    return array[end];
}

bool Queue::empty() {
    if(start!=-1 && end!=-1)
        return false;
    else 
        return true;
}

bool Queue::full() {
    if((end+1)%ARRAY_SIZE==start)
        return true;
    else 
        return false;
}

int main() {
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    printf("Full: %d\n",q.full());
    q.push(4);
    printf("Full: %d\n",q.full());
    printf("%d\n",q.front());
    q.pop();
    printf("%d\n",q.front());
    q.pop();
    q.push(1);
    q.push(2);
    printf("%d\n",q.front());
    q.pop();
    printf("%d\n",q.front());
    q.pop();
    printf("%d\n",q.front());
    q.pop();
    printf("%d\n",q.front());
    q.pop();
    printf("Empty: %d\n",q.empty());
}