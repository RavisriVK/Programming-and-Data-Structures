#include<iostream>
#include<stack>
using namespace std;

#define INF (1.0/0.0)

int main() {
    int v, e;
    cin>>v>>e;
    double A[v][v];
    int P[v][v];
    for(int i=0; i<v; i++) {
        for(int j=0; j<v; j++) {
            A[i][j]=INF;
            P[i][j]=i+1;
        }
    }
    int in1, in2;
    double in3;
    for(int i=0; i<e; i++) {
        cin>>in1>>in2>>in3;
        A[in1-1][in2-1]=in3;
    }
    for(int m=0; m<v; m++) {
        for(int i=0; i<v; i++) {
            for(int j=0; j<v; j++) {
                if(A[i][j] > A[i][m] + A[m][j]) {
                    A[i][j]=A[i][m] + A[m][j];
                    P[i][j]=P[m][j];
                }
            }
        }
    }
    for(int i=0; i<v; i++) {
        for(int j=0; j<v; j++)
            cout<<A[i][j]<<" ";
        cout<<"\n";
    }

    for(int i=0; i<v; i++) {
        for(int j=0; j<v; j++) {
            if(A[i][j]==INF) continue;
            int last=j;
            stack<int> s;
            while(last!=i) {
                s.push(last+1);
                last=P[i][last]-1;
            }
            s.push(i+1);
            while(!s.empty()) {
                cout<<s.top()<<" ";
                s.pop();
            }
            cout<<"\n";
        }
    }
}