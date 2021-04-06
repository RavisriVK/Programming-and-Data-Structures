#include<iostream>
using namespace std;

int v, e;
int *t, *mx;
bool *visited;
bool **A;

int dfs(int vtx) {
    visited[vtx]=true;
    int longest=t[vtx];
    for(int i=0; i<v; i++) {
        if(A[vtx][i]) {
            if(!visited[i])
                dfs(i);
            longest=max(longest, t[vtx] + mx[i]);
        }
    }
    mx[vtx]=longest;
    return longest;
}

int DFS() {
    int longest=0;
    for(int i=0; i<v; i++) {
        if(!visited[i])
            dfs(i);
        longest=max(longest, mx[i]);
    }
    return longest;
}

int main()
{
    cout<<"Enter number of tasks and number of constraints: ";
    cin>>v>>e;
    t=new int[v];
    mx=new int[v];
    cout<<"Enter times required for each task: ";
    for(int i=0; i<v; i++)
        cin>>t[i];
        
    A=new bool*[v];
    for(int i=0; i<v; i++)
        A[i]=new bool[v];

    for(int i=0; i<v; i++)
        for(int j=0; j<v; j++)
            A[i][j]=false;

    int in1, in2;
    cout<<"Enter the constraints in the format \"i j\" where ith task must be completed before jth task\n";
    for(int i=0; i<e; i++) 
    {
        cin>>in1>>in2;
        A[in1-1][in2-1]=true;
    }
    visited=new bool[v];
    for(int i=0; i<v; i++)
        visited[i]=false;

    int ans=DFS();
    cout<<"\nMinimum Time Required to Complete All Tasks: "<<ans<<"\n";
}