#include<iostream>
using namespace std;

/* Kth element where K is an index starting from 0 */
/*
int Kth(int *a, int n, int k) 
{
    int pivot=a[n-1];
    int i=0;
    for(int j=0; j<n-1; j++)
        if(a[j]<pivot)
            swap(a[i++], a[j]);
    swap(a[i], a[n-1]);

    if(i==k)
        return a[i];
    else if(i>k)
        return Kth(a, i, k);
    else 
        return Kth(a+i+1, n-1-i, k-i-1);
}
*/
int Kth(int *a, int n, int k) 
{
    int pivot=a[n-1];
    int i=0, j=n-2;
    for(int k=0; k<=j; k++)
        if(a[k]<pivot)
            swap(a[i++], a[k]);
        else if(a[k]>pivot)
            swap(a[j--], a[k--]);
    swap(a[i], a[n-1]);

    if(i==k)
        return a[i];
    else if(i>k)
        return Kth(a, i, k);
    else 
        return Kth(a+i+1, n-1-i, k-i-1);
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
    k--;
    cout<<(Kth(a, n, k))<<"\n";
}