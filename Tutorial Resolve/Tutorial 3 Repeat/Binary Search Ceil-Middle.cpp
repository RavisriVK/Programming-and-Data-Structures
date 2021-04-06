#include<iostream>
using namespace std;

int BinarySearch(int *a, int n, int key)
{
    int low=0, high=n-1, middle;
    while(low<=high)
    {
        middle=(low+high+1)/2;
        if(a[middle]<key)
            low=middle+1;
        else if(a[middle]>key)
            high=middle-1;
        else 
            return middle;
    }
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
    cout<<(BinarySearch(a, n, k))<<"\n";
}