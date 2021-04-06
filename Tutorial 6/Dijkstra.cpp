#include<iostream>
#include<queue>
#include<list>
using namespace std;

#define INF (1.0/0.0)

typedef pair<double, int> pdi;
list<pdi> *AdjList;
priority_queue< pdi, vector<pdi>, greater<pdi> > minHeap;
double *d;

int main() {
    int v, e;
    cin>>v>>e;
    AdjList=new list<pdi>[v];
    
    d=new double[v];
    for(int i=0; i<v; i++)
        d[i]=INF;
    d[0]=0;

    int in1, in2;
    double in3;
    for(int i=0; i<e; i++) {
        cin>>in1>>in2>>in3;
        AdjList[in1-1].push_back(pdi(in3, in2-1));
    }

    for(int i=0; i<v; i++)
        minHeap.push(pdi(d[i], i));
    for(int i=0; i<v; i++) {
        pdi w=minHeap.top();
        minHeap.pop();
        d[w.second]=w.first;
        /* No need to use decreaseKey! Simply add an updated cost,vertex pair which will be popped first!!! */
        for(list<pdi>::iterator i=AdjList[w.second].begin(); i!=AdjList[w.second].end(); i++) {
            if( d[w.second] + (*i).first < d[(*i).second]) {
                d[(*i).second]=d[w.second] + (*i).first;
                minHeap.push(pdi(d[(*i).second], (*i).second));
            }
        }
    }
    for(int i=0; i<v; i++)
        cout<<d[i]<<" ";
    cout<<"\n";
}