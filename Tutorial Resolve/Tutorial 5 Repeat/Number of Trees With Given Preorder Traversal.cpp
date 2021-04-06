#include<iostream>
using namespace std;

/* N is number of vertices in preorder traversal */
int treeCount(int n)
{
    int a[n+1];
    memset(a, 0, (n+1)*sizeof(int));
    a[0]=1; a[1]=1;
    for(int i=2; i<=n; i++) 
        for(int j=0; j<i; j++) 
            a[i]+= a[j]*a[i-1-j];
    return a[n];
}

int main()
{
    cout<<treeCount(3)<<"\n";
}