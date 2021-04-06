#include<iostream>
#include<queue>
using namespace std;

int v, e;
bool **A;
bool *visited;

bool BFS() {
    queue<int> Q;
    for(int i=0; i<v; i++) {
        if(!visited[i]) {
            Q.push(i);
            while(!Q.empty()) {
                int vtx=Q.front();
                Q.pop();
                for(int j=0; j<v; j++)
                    if(A[i][j] && !visited[j])
                        Q.push(j);
            }
        }
    }
}

bool dfs(int vtx, int parent) {
    visited[vtx]=true;
    for(int i=0; i<v; i++)
        if(i!=parent && A[vtx][i] && (visited[i] || dfs(i, vtx)) ) 
            return true;
    return false;
}

bool DFS() {
    for(int i=0; i<v; i++)
        if(!visited[i] && dfs(i, -1))
            return true;
    return false;
}

int main() {
    cin>>v>>e;

    visited=new bool[v];

    A=new bool*[v];
    for(int i=0; i<v; i++) {
        A[i]=new bool[v];
        for(int j=0; j<v; j++)
            A[i][j]=false;
    }

    int in1, in2;
    for(int i=0; i<e; i++) {
        cin>>in1>>in2;
        A[in1-1][in2-1]=true;
        A[in2-1][in1-1]=true;
    }

    if(DFS())
        cout<<"Found Cycle\n";
    else
        cout<<"Cycle not found\n";
    
}