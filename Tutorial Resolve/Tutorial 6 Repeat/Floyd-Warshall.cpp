#include<iostream>
using namespace std;

#define INF (1.0/0.0)

int main() {
    int n;
    cin>>n;
    double A[n][n];
    int P[n][n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            A[i][j]=INF;
            P[i][j]=i;
        }
        A[i][i]=0;
    }
    int e, in1, in2, cost;
    cin>>e;
    for(int i=0; i<e; i++) {
        cin>>in1>>in2>>cost;
        A[in1][in2]=cost;
    }

    for(int m=0; m<n; m++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(A[i][j]>(A[i][m]+A[m][j])) {
                    A[i][j]=A[i][m]+A[m][j];
                    P[i][j]=m;
                }
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<A[i][j]<<" ";
        }
        cout<<"\n";
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<P[i][j]<<" ";
        }
        cout<<"\n";
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(A[i][j]==INF) continue;
            int last=j;
            while(last!=i) {
                cout<<last<<" ";
                last=P[i][last];
            }
            cout<<i<<"\n";
        }
    }

}