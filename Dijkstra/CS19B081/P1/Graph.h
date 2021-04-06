#include "MinHeap.h"
#include "List.h"

/* This is a specialized Graph ADT */
class Graph 
{
    private:
        int v;                              // Stores number of vertices
        List *adjacencyList;      // Self-explanatory
        MinHeap* S;                         // Keeps V-S in a priority queue (min heap) as per Dijkstra's algorithm
        WeightType *d;                      // Keeps an updated array of shortest distances from source
        bool *found;                        // Notes whether a vertex's minimum distance from the source is known

    public:
        /* Adds an undirected edge of a given weight between two specified vertex indices */
        void addEdge(NodeType firstNode, NodeType secondNode, WeightType weight);
        /* Initializes all the private fields */
        Graph(int verticeCount);
        /* Self explanatory */
        void findShortestDistances();
        /* Self explanatory */
        void printShortestDistances();
 };