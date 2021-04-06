#include<iostream>
#include<list>
using namespace std;

int n;
list<int>* A;
bool* visited;

bool dfs(int vertex, int parent) {
    visited[vertex]=true;
    for(list<int>::iterator i=A[vertex].begin(); i!=A[vertex].end(); i++)
        if(*i!=parent && (visited[*i] || dfs(*i, vertex)))
            return true;
    return false;
}

bool DFS() {
    memset(visited, 0, n*sizeof(bool));
    for(int i=0; i<n; i++)
        if(!visited[i] && dfs(i, -1))
            return true;
    return false;
}

int main() {
    cin>>n;
    int e;
    cin>>e;
    visited=new bool[n];
    A=new list<int>[n];
    int in1, in2;
    for(int i=0; i<e; i++) {
        cin>>in1>>in2;
        A[in1].push_back(in2);
        A[in2].push_back(in1);
    }
    if(DFS())   cout<<"Cycle\n"; else cout<<"No Cycle\n";
}