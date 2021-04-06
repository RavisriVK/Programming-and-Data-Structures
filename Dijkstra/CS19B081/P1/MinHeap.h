#include "Nodes.h"

/* Using this as a definition for infinity is very useful */
#define INF (1.0/0.0)

/* The class MinHeap defines an ADT Heap. */
class MinHeap {
    private:
        HeapNode **priority;                             
        int *nodeLocations;
        int last;
    public:
        MinHeap(int size);                                  /* initializes 'last' variable, creates arrays */
        void insertHeap(NodeType ind, WeightType dist);     /* correctly inserts a new element into the heap */
        HeapNode* deleteRoot();                             /* deletes the root and reorganizes the array */
        void decreaseKey(NodeType ind, WeightType dist);    /* decreases minDistance of specified node and reorganizes the array */
    private:
        void swap(int p1, int p2);                          /* swaps elements at different positions in array */
};