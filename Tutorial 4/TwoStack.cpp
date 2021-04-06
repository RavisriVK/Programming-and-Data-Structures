#include<iostream>
using namespace std;

#define StackSize 4

class TwoStack {
    public:
        TwoStack();
        void pop1();
        int top1();
        void push1(int val);
        void pop2();
        int top2();
        void push2(int val);
    private:
        int *array;
        int end1, end2;
};

TwoStack::TwoStack() {
    end1=0;
    end2=StackSize-1;
    array=new int[StackSize];
}

void TwoStack::pop1() {
    if(end1>0)
        end1--;
}

void TwoStack::pop2() {
    if(end2<StackSize-1)
        end2++;
}

int TwoStack::top1() {
    if(end1>0)
        return array[end1-1];
    else 
        return -1;
}

int TwoStack::top2() {
    if(end2<StackSize-1)
        return array[end2+1];
    else
        return -1;
}

void TwoStack::push1(int val) {
    if(end1<=end2) {
        array[end1]=val;
        end1++;
    }
}

void TwoStack::push2(int val) {
    if(end2>=end1) {
        array[end2]=val;
        end2--;
    }
}

int main() {
    TwoStack t;
    t.push1(2);
    t.push2(3);
    t.push1(15);
    t.push2(21);
    printf("%d\n",t.top1());
    t.pop1();
    printf("%d\n",t.top1());
    t.pop1();
    printf("%d\n",t.top2());
    t.pop2();
    printf("%d\n",t.top2());
    t.pop2();
}