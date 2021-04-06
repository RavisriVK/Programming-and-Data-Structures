#include<iostream>
using namespace std;


int kthElementInUnion(int *a, int *b, int n, int k)
{
    int left=max(0, k-1-n), right=min(k-1, n-1), middle;
    while(left<=right)
    {
        middle=(left+right)/2;
        if((k-2-middle<0 || a[middle]>=b[k-2-middle]) && (k-1-middle>=n || a[middle]<=b[k-1-middle]))
            return a[middle];
        else if(k-2-middle>=0 && a[middle]<b[k-2-middle])
            left=middle+1;
        else
            right=middle-1;
    }
    left=max(0, k-1-n);
    right=min(k-1, n-1);
    while(left<=right)
    {
        middle=(left+right)/2;
        if((k-2-middle<0 || b[middle]>=a[k-2-middle]) && (k-1-middle>=n || b[middle]<=a[k-1-middle]))
            return b[middle];
        else if(k-2-middle>=0 && b[middle]<a[k-2-middle])
            left=middle+1;
        else
            right=middle-1;
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    int b[n];
    for(int i=0; i<n; i++)
        cin>>b[i];
    int k;
    double median=kthElementInUnion(a, b, n, n);
    median+=kthElementInUnion(a, b, n, n+1);
    median/=2;
    cout<<median<<"\n";
}