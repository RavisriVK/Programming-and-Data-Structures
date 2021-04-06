#include<iostream>
using namespace std;

int main()
{
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    int t1, t2, t3, t4;

    /* Sorting by decision tree */
    if(a<b) {
        t1=a;
        t2=b;
    } else {
        t1=b;
        t2=a;
    }
    a=t1; b=t2;
    int a2, b2, c2;
    if(b<c) {
        t1=a;
        t2=b;
        t3=c;
    } else if(a<c) {
        t1=a;
        t2=c;
        t3=b;
    } else {
        t1=c;
        t2=a;
        t3=b;
    }
    a=t1; b=t2; c=t3;
    if(d>b) {
        if(d>c) {
            t1=a;
            t2=b;
            t3=c;
            t4=d;
        } else {
            t1=a;
            t2=b;
            t3=d;
            t4=c;
        }
    } else {
        if(a<d) {
            t1=a;
            t2=d;
            t3=b;
            t4=c;
        } else {
            t1=d;
            t2=a;
            t3=b;
            t4=c;
        }
    }
    a=t1; b=t2; c=t3; d=t4;
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
}