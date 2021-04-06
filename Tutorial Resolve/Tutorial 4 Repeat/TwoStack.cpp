#include<iostream>
using namespace std;

template<typename Object>
class TwoStack {
    public:
        TwoStack(int size=100) {
            this->size=size;
            array=new Object[size];
            end1=-1; end2=size;
        }
        void push1(Object element) {
            if(!full())
                array[++end1]=element;
        }
        void push2(Object element) {
            if(!full())
                array[--end2]=element;
        }
        void pop1() {
            if(!empty1())
                end1--;
        }
        void pop2() {
            if(!empty2())
                end2++;
        }
        Object top1() {
            if(!empty1())
                return array[end1];
            else 
                return Object();
        }
        Object top2() {
            if(!empty2())
                return array[end2];
            else 
                return Object();
        }
        bool full() {
            return (end1+1)==end2;
        }
        bool empty1() {
            return end1==-1;
        }
        bool empty2() {
            return end2==size;
        }
    private:
        Object *array;
        int end1, end2;
        int size;
};

int main() {
    TwoStack<int> t;
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