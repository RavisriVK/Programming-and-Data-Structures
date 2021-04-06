#include<iostream>
using namespace std;
#define INF (1.0/0.0)

double dfs(double** A, bool* visited, int vtx, int v, double* mx) {
    visited[vtx]=true;
    double longest=0;
    for(int i=0; i<v; i++) {
        if(A[vtx][i]!=INF) {
            if(!visited[i])
                dfs(A, visited, i, v, mx);
            longest=max(longest, A[vtx][i] + mx[i]);
        }
    }
    mx[vtx]=longest;
    return longest;
}

double DFS(double** A, bool* visited, int v, double *mx) {
    double longest=0;
    for(int i=0; i<v; i++) {
        if(!visited[i])
            dfs(A, visited, i, v, mx);
        longest=max(longest, mx[i]);
    }
    return longest;
}

int main()
{
    int v, e;
    cin>>v>>e;

    bool visited[v];
    double mx[v];
    for(int i=0; i<v; i++) {
        visited[i]=false;
        mx[i]=0;
    }

    double **A;
    A=new double*[v];
    for(int i=0; i<v; i++)
        A[i]=new double[v];

    for(int i=0; i<v; i++)
        for(int j=0; j<v; j++)
            A[i][j]=INF;

    int in1, in2;
    double in3;
    for(int i=0; i<e; i++) {
        cin>>in1>>in2>>in3;
        A[in1-1][in2-1]=in3;
    }

    cout<<DFS(A, visited, v, mx)<<"\n";

}