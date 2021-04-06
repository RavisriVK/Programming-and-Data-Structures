#include <iostream>
#include "Heap.h"
using namespace std;

/*===================================================================
 *  Function: createHeap
 *  Functionality: initializes 'last' variable
 *  Input: None
 *  Output: None
 * ==================================================================*/
void Heap::createHeap()
{
  last=0;
}

/*===================================================================
 *  Function: swap
 *  Functionality: swaps elements at different positions in array
 *  Input: Positions of swap
 *  Output: None
 * ==================================================================*/
void Heap::swap(Position p1, Position p2)
{
  /* Check if the positions are valid */
  if(p1<0 || p1>=last || p2<0 || p2>=last)
    return;
  ElementType temp=priority[p1];
  priority[p1]=priority[p2];
  priority[p2]=temp;
}

/*===================================================================
 *  Function: insertHeap
 *  Functionality: correctly inserts a new element into the heap
 *  Input: element to be inserted
 *  Output: None
 * ==================================================================*/
void Heap::insertHeap(ElementType x)
{
  /* Insert at last position and increment 'last' */
  Position insertAt=last;
  priority[last]=x;
  last++;

  /* While value is greater than value at parent node, go up the tree */
  while(insertAt>0 && priority[insertAt]>priority[(insertAt-1)/2])
  {
    /* Move the element up the tree */
    swap(insertAt, (insertAt-1)/2);
    /* Make the index equal to the index of the parent node */
    insertAt=(insertAt-1)/2;
  }

}

/*===================================================================
 *  Function: deleteRoot
 *  Functionality: deletes the root and reorganizes the array
 *  Input: None
 *  Output: None
 * ==================================================================*/
ElementType Heap::deleteRoot()
{
    /* Put the last element at the begin of the array and store the largest element to be printed later */
    ElementType out=priority[0];
    priority[0]=priority[last-1];
    last--;

    /* 'moveTo' stores the position to which the new first element will finally be shifted */
    Position moveTo=0;

    /* leftVal and rightVal store the values stored in the left and right subtrees if they exist, or -10000 if not */
    ElementType leftVal= (2*moveTo+1)>=last ? (-10000) : priority[2*moveTo+1];
    ElementType rightVal= (2*moveTo+2)>=last ? (-10000) : priority[2*moveTo+2];

          /*This condition checks that the values in the left and right subtrees aren't both greater than value at the current node*/
    while(priority[moveTo]<leftVal || priority[moveTo]<rightVal)
    {
      /*If the value in the left subtree is greater than the value in the right subtree, we swap node with left child and similarly in the other case*/ 
      if(leftVal>=rightVal)
      {
        swap(moveTo, 2*moveTo+1);
        moveTo=2*moveTo+1;
      }
      else
      {
        swap(moveTo, 2*moveTo+2);
        moveTo=2*moveTo+2;
      }

      /*Note that it won't be a problem if the children aren't in the array- then leftVal and rightVal will hold -10000 */
      /* leftVal and rightVal store the values stored in the left and right subtrees if they exist, or -10000 if not */
      leftVal= (2*moveTo+1)>=last ? (-10000) : priority[2*moveTo+1];
      rightVal= (2*moveTo+2)>=last ? (-10000) : priority[2*moveTo+2];
    }

    return out;
}

/*===================================================================
 *  Function: empty
 *  Functionality: checks if heap is empty
 *  Input: None
 *  Output: None
 * ==================================================================*/
int Heap::empty()
{
  return last==0;
}

/*===================================================================
 *  Function: printHeap
 *  Functionality: prints level order traversal of tree
 *  Input: None
 *  Output: None
 * ==================================================================*/
void Heap::printHeap()
{
  for(Position i=0; i<last; i++)
    cout<<priority[i]<<" ";
  if(last==0)
    cout<<"EMPTY HEAP";
  cout<<"\n";
}