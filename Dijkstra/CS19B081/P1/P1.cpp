#include<iostream>
#include "Graph.h"
using namespace std;


int main()
{
    /* Reading in inputs */
    int m, n;
    cin>>m>>n;

    int node1, node2;
    double weight;

    /* Create a graph object */
    Graph G(m);

    /* Add the edges to the adjacency list */
    for(int i=0; i<n; i++)
    {
        cin>>node1>>node2>>weight;
        if(node1!=node2)
        G.addEdge(node1, node2, weight);
    }
    
    G.findShortestDistances();
    G.printShortestDistances();
}