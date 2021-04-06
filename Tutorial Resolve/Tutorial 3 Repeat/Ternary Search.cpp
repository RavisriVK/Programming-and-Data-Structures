#include<iostream>
using namespace std;

int TernarySearchV1(int *a, int n, int key)
{
    int low=0, high=n-1, d1, d2;
    while(high-low>1)
    {
        d1=(2*low+high)/3;
        d2=(low+2*high)/3;
        if(a[d1]>=key) {
            high=d1;
        } else if(a[d2]<=key) {
            low=d2;
        } else {
            low=d1+1;
            high=d2-1;
        }
    }
    if(a[low]==key) return low;
    else if(a[high]==key) return high;
    else return -1;
}

int TernarySearchV2(int *a, int low, int high, int key)
{
    int d1, d2;
    d1=(2*low+high)/3;
    d2=(low+2*high)/3;
    if(a[d1]==key)
        return d1;
    else if(a[d2]==key)
        return d2;
    else if(a[d1]>key && d1>0)
        return TernarySearchV2(a, 0, d1-1, key);
    else if(a[d2]<key && (high-d2)>0)
        return TernarySearchV2(a, d2+1, high, key);
    else if(key>a[d1] && key<a[d2] && (d2-d2-1)>0)
        return TernarySearchV2(a, d1+1, d2-1, key);
    else
        return -1;

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
    cout<<(TernarySearchV1(a, n, k))<<" # ";
    cout<<(TernarySearchV2(a, 0, n-1, k))<<"\n";
}