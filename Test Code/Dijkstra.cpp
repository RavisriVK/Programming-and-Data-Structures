#include<iostream>
using namespace std;

#define INF (1.0/0)

int main()
{
    int n;
    cin>>n;
    double C[n][n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) {
            cin>>C[i][j];
            if(C[i][j]<0) C[i][j]=INF;
        }
    bool S[n];
    int modS=0;
    for(int i=0; i<n; i++)
        S[i]=false;
    double d[n];
    d[0]=0;
    for(int i=1; i<n; i++)
        d[i]=INF;
    while(modS!=n) 
    {
        for(int i=0; i<n; i++)
            cout<<d[i]<<" ";
        cout<<"\n";
        int w=-1;
        for(int i=0; i<n; i++)
            if(!S[i] && (w==-1 || d[w]>d[i]) )
                w=i;
        S[w]=true; modS++;
        for(int i=0; i<n; i++)
            if(d[i]>(d[w] + C[w][i]))
                d[i]=d[w] + C[w][i];
    }
    for(int i=0; i<n; i++)
        cout<<d[i]<<" ";
    cout<<"\n";
}