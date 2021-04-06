#include<iostream>
using namespace std;

template<typename Object>
class Queue {
    public:
        Queue(int size=1000) {
            this->size=size;
            array=new Object[size];
            start=-1;
            end=-1;
        }
        void push(Object element) {
            if(empty()) {
                start=end=0;
                array[end]=element;
            } else if(!full()) {
                end=(end+1)%size;
                array[end]=element;
            } 
        }
        void pop() {
            if(!empty()) {
                if(start==end)
                    start=end=-1;
                else
                    start=(start+1)%size;
            }
        }
        Object front() {
            if(!empty())
                return array[start];
            else
                return Object();
        }
        Object rear() {
            if(!empty())
                return array[end];
            else 
                return Object();
        }
        bool empty() {
            return (start==-1 && end==-1);
        }
        bool full() {
            return ((end+1)%size)==start;
        }
        void print() {
            if(!empty()) {
                for(int i=start; i!=end; i=(i+1)%size)
                    cout<<array[i]<<" ";
                cout<<array[end]<<"#\n";
            } else {
                cout<<"empty\n";
            }
        }
    private:
        Object* array;
        int size;
        int start;
        int end;
};

int main()
{
    Queue<int> q(100);
    /*q.push(1);
    q.push(2);
    q.push(3);
    q.print();
    q.pop();
    q.pop();
    q.pop();
    q.print();
    q.push(1);
    q.push(2);
    q.push(3);
    q.print();
    q.pop();
    q.pop();
    q.pop();
    q.print();*/
    
    int n;
    cin>>n;
    int op, el;
    for(int i=0; i<n; i++) {
        cin>>op;
        if(op==1) {
            cin>>el;
            q.push(el);
        } else if(op==2) {
            q.pop();
        } else if(op==3) {
            q.print();
        }
    }
}