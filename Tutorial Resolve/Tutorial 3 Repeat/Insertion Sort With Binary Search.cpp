#include<iostream>
using namespace std;

void insertionSort(int *a, int n)
{
    for(int i=1; i<n; i++) 
    {
        int insertAt=i-1;
        int low=-1, high=i;
        
        for(int middle=(low+high)/2; high-low>1; middle=(low+high)/2)
            if(a[i]<a[middle])
                high=middle-1;
            else
                low=middle;

        int hold=a[i];
        for(int j=i; j-low>1; j--)
            a[j]=a[j-1];
        a[low+1]=hold;
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    insertionSort(a, n);
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}