#include<iostream>
#include<list>
using namespace std;

int n;
int* longest;
int* times;
list<int>* A;
bool* visited;
int costLongestPath;

void dfs(int v) {
    visited[v]=true;
    cout<<v<<" ";
    for(list<int>::iterator i=A[v].begin(); i!=A[v].end(); i++) {
        if(!visited[*i])
            dfs(*i);
        longest[v]=max(longest[v], times[v]+longest[*i]);
    }
    costLongestPath=max(costLongestPath, longest[v]);
}

void DFS() {
    memset(visited, 0, sizeof(bool)*n);
    for(int i=0; i<n; i++)
        if(!visited[i]) {
            dfs(i);
            cout<<"\n";
        }
}

int main() {
    cin>>n;
    longest=new int[n];
    times=new int[n];
    A=new list<int>[n];
    visited=new bool[n];
    for(int i=0; i<n; i++) {
        cin>>times[i];
        longest[i]=times[i];
    }
    int constraints;
    // in1 in2 => in1 is required for in2
    cin>>constraints;
    int in1, in2;
    for(int i=0; i<constraints; i++) {
        cin>>in1>>in2;
        A[in1].push_back(in2);
    }
    DFS();
    cout<<costLongestPath<<"\n";
}