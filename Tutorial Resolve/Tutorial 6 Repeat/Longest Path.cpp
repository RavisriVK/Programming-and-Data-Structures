#include<iostream>
#include<list>
using namespace std;

int n;
bool* visited;
int* longest;
int lpath=0;
list< pair<int, int> >* A;

void dfs(int v) {
    visited[v]=true;
    for(list< pair<int, int> >::iterator i=A[v].begin(); i!=A[v].end(); i++) {
        if(!visited[(*i).first])
            dfs((*i).first);
        longest[v]=max(longest[v], (*i).second + longest[(*i).first]);
    }
    lpath=max(lpath, longest[v]);
}

void DFS() {
    memset(visited, 0, n*sizeof(int));
    memset(longest, 0, n*sizeof(int));
    for(int i=0; i<n; i++)
        if(!visited[i])
            dfs(i);
}

int main() {
    cin>>n;
    visited=new bool[n];
    longest=new int[n];
    A=new list< pair<int, int> >[n];

    int e;
    cin>>e;
    int v1, v2, weight;
    for(int i=0; i<e; i++) {
        cin>>v1>>v2>>weight;
        A[v1].push_back(pair<int, int>(v2, weight));
    }

    DFS();
    cout<<lpath<<"\n";
}