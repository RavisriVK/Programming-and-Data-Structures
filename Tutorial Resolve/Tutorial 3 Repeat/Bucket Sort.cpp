#include<iostream>
using namespace std;

void bucketSort(int *a, int n, int lower_bound, int upper_bound)
{
    int buckets[upper_bound-lower_bound];
    memset(buckets, 0, sizeof(int)*(upper_bound-lower_bound));
    for(int i=0; i<n; i++)
        buckets[a[i]-lower_bound]++;
    int element_count=0;
    for(int i=0; i<(upper_bound-lower_bound); i++)
        while((buckets[i]--)>0)
            a[element_count++]=lower_bound+i;
}

int main()
{
    int n;
    cin>>n;
    int a[n], minElement, maxElement;
    cin>>a[0];
    minElement=maxElement=a[0];
    for(int i=1; i<n; i++)
    {
        cin>>a[i];
        minElement=min(minElement, a[i]);
        maxElement=max(maxElement, a[i]);
    }
    bucketSort(a, n, minElement, maxElement+1);
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}