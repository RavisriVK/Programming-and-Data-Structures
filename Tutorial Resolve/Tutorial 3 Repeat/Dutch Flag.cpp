#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    int i=0, j=n-1;
    for(int k=0; k<=j; k++)
    {
        if(a[k]==0)
            swap(a[i++], a[k]);
        else if(a[k]==2)
            swap(a[j--], a[k--]);
    }

    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}