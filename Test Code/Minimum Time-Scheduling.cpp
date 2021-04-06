#include<iostream>
#include<list>
using namespace std;

int n;
int* minTime;
int* times;
list<int>* A;
bool* visited;
int costLongestPath;

void dfs(int v) {
    visited[v]=true;
    cout<<v<<" ";
    for(list<int>::iterator i=A[v].begin(); i!=A[v].end(); i++) {
        if(visited[*i])
            dfs(*i);
        minTime[v]=max(minTime[v], times[v]+minTime[*i]);
    }
    costLongestPath=max(costLongestPath, minTime[v]);
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
    minTime=new int[n];
    times=new int[n];
    A=new list<int>[n];
    visited=new bool[n];
    for(int i=0; i<n; i++) {
        cin>>minTime[i];
        times[i]=minTime[i];
    }
    int constraints;
    // in1 in2 => in1 is required for in2
    cin>>constraints;
    int in1, in2;
    for(int i=0; i<constraints; i++) {
        cin>>in1>>in2;
        A[in2].push_back(in1);
    }
    DFS();
    cout<<costLongestPath<<"\n";
}