#include<iostream>
using namespace std;

int BinarySearchV1(int *a, int n, int key)
{
    int low=0, high=n-1, middle;
    while(low<=high)
    {
        middle=(low+high)/2;
        if(a[middle]<key)
            low=middle+1;
        else if(a[middle]>key)
            high=middle-1;
        else
            return middle;
    }
    return n;
}

int BinarySearchV2(int *a, int n, int key)
{
    int low=0, high=n-1, middle;
    while(high-low>1)
    {
        middle=(low+high)/2;
        if(a[middle]<=key)
            low=middle;
        else 
            high=middle;
    }
    if(a[low]==key)
        return low;
    else if(a[high]==key)
        return high;
    else 
        return n;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    int k;
    cin>>k;
    cout<<(BinarySearchV1(a, n, k))<<" # ";
    cout<<(BinarySearchV2(a, n, k))<<"\n";   
}