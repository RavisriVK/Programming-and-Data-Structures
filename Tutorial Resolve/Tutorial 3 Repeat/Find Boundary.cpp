#include<iostream>
using namespace std;

int boundary;

bool check(int n)
{
    return n>=boundary;
}

int findBoundary()
{
    int low=0, high=1;
    while(!check(high))
    {
        low=high;
        high*=2;
    }
    int middle=(low+high)/2;
    while(high>low)
    {
        if(check(middle)==0)
            low=middle+1;
        else    
            high=middle;
        middle=(low+high)/2;
    }
    return low;
}

int main()
{
    cin>>boundary;
    cout<<(findBoundary())<<"\n";
}
