#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    char a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    int zCount=0;
    for(int i=0; i<n; i++)
        if(a[i]=='0')
            swap(a[zCount++], a[i]);
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}