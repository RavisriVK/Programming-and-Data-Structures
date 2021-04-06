#include "Graph.h"
#include <iostream>
using namespace std;

/* Adds an undirected edge of a given weight between two specified vertex indices */
void Graph::addEdge(NodeType firstNode, NodeType secondNode, WeightType weight)
{
    adjacencyList[firstNode].pushBack(HeapNode(secondNode, weight));
    adjacencyList[secondNode].pushBack(HeapNode(firstNode, weight));
}

/* Initializes all the private fields */
Graph::Graph(int verticeCount)
{
    /* This is obvious */
    v=verticeCount;
    /* Here we are creating a MinHeap object */
    S=new MinHeap(verticeCount);
    /* We allocate memory for the adjacency list here */
    adjacencyList=new List[verticeCount];

    /* We allocate memory for the 'd' and 'found' arrays here */
    d=new WeightType[verticeCount];
    found=new bool[v];

    /* We initialize d, and found arrays here */
    /* Also, we insert all vertices into the MinHeap */
    found[0]=false;
    d[0]=0;
    S->insertHeap(0, 0.0);

    for(int i=1; i<verticeCount; i++)
    {
        d[i]=INF;
        S->insertHeap(i, INF);
        found[i]=false;
    }
}

/* Self explanatory */
void Graph::findShortestDistances()
{
    for(int i=0; i<v; i++)
    {
        /* Here we obtain the vertex with the smallest distance (through vertices whose minimum distances are known) from source among remaining vertices */ 
        HeapNode* w=S->deleteRoot();
        NodeType ind=w->nodeIndex;

        /* We update the 'd' value accordingly */
        d[ind]=w->minDistance;

        /* Now we traverse through vertices adjacent to w */
        for(Position j=adjacencyList[ind].first(); j!=adjacencyList[ind].end(); j=adjacencyList[ind].next(j))
        {
            HeapNode temp=adjacencyList[ind].retrieveValue(j);
            WeightType possibility=d[ind] + temp.minDistance;

            /* We update 'd' value if we can make it smaller */
            if(d[temp.nodeIndex]>possibility)
            {
                d[temp.nodeIndex]=possibility;
                S->decreaseKey(temp.nodeIndex, possibility);
            }
        }

    }
}
/* Self explanatory */
void Graph::printShortestDistances()
{
    for(int i=0; i<v; i++)
        cout<<i<<" "<<d[i]<<"\n";
}