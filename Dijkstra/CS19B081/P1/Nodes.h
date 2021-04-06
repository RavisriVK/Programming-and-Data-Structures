#ifndef NODES_H
#define NODES_H

#include <iostream>

/* We can make WeightType double so as to make use of the inbuilt 'infinity arithmetics' of floating point numbers */
typedef double WeightType;

/* NodeType is simply the vertice index */
typedef int NodeType;

/* This structure only needs to have the index of the node and the minimum distance from source */
typedef struct HeapNode
{
    NodeType nodeIndex;
    WeightType minDistance;
    HeapNode(NodeType ind=-1, WeightType dist=-1)
    {
        nodeIndex=ind;
        minDistance=dist;
    }
} ElementType;

/* This is a node for the list described in lab 4/5 */
struct listNode 
{
    ElementType data;
    listNode* next;
    listNode(ElementType val=0, listNode* nxt=NULL) /* listNode constructor */
    {
        data=val;
        next=nxt;
    }
};
typedef listNode* Position;

#endif