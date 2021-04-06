 #include <iostream>
using namespace std;

typedef double WeightType;
typedef int NodeType;

struct HeapNode
{
    NodeType nodeIndex;
    WeightType minDistance;
    HeapNode(NodeType ind, WeightType dist)
    {
        nodeIndex=ind;
        minDistance=dist;
    }
};


//#define INF (1.0/0)

/* The class MinHeap defines an ADT Heap. */
class MinHeap {
    private:
        HeapNode **priority;                             
        int *nodeLocations;
        int last;
        const double INF;
    public:
        /*===================================================================
        *  Constructor: MinHeap
        *  Functionality: initializes 'last' variable, creates arrays
        *  Input: None
        *  Output: None
        * ==================================================================*/
        MinHeap(int size, double infinity=(1.0/0.0)) : INF(infinity)
        {
            priority=new HeapNode *[size];
            nodeLocations=new int[size];
            for(int i=0; i<size; i++)
            {
                priority[i]=NULL;
                nodeLocations[i]=-1;
            }
            last=0;
        }

        /*===================================================================
        *  Function: insertHeap
        *  Functionality: correctly inserts a new element into the heap
        *  Input: element to be inserted
        *  Output: None
        * ==================================================================*/
        void insertHeap(NodeType ind, WeightType dist)
        {
            /* Insert at last position and increment 'last' */
            int insertAt=last;
            priority[last]=new HeapNode(ind, dist);
            last++;

            nodeLocations[ind]=insertAt;

            /* While value is lesser than value at parent node, go up the tree */
            while(insertAt>0 && priority[insertAt]->minDistance<priority[(insertAt-1)/2]->minDistance)
            {
                /* Make sure node location is updated */
                nodeLocations[priority[(insertAt-1)/2]->nodeIndex]=insertAt;
                /* Move the element up the tree */
                swap(insertAt, (insertAt-1)/2);
                /* Make the index equal to the index of the parent node */
                insertAt=(insertAt-1)/2;
                /* Make sure node location is updated */
                nodeLocations[ind]=insertAt;
            }

        }

        /*===================================================================
        *  Function: deleteRoot
        *  Functionality: deletes the root and reorganizes the array
        *  Input: None
        *  Output: None
        * ==================================================================*/
        HeapNode* deleteRoot()
        {
            /* Make sure node locations are updated */
            nodeLocations[priority[0]->nodeIndex]=-1;
            nodeLocations[priority[last-1]->nodeIndex]=0;

            /* Put the last element at the begin of the array and store the smallest element to be printed later */
            HeapNode* out=priority[0];
            priority[0]=priority[last-1];
            last--;

            /* 'moveTo' stores the position to which the new first element will finally be shifted */
            int moveTo=0;

            /* leftVal and rightVal store the values stored in the left and right subtrees if they exist, or INF if not */
            HeapNode* leftVal= (2*moveTo+1)>=last ? new HeapNode(-1, INF): priority[2*moveTo+1];
            HeapNode* rightVal= (2*moveTo+2)>=last ? new HeapNode(-1, INF) : priority[2*moveTo+2];

            /*This condition checks that the values in the left and right subtrees aren't both greater than value at the current node*/
            while(priority[moveTo]->minDistance>leftVal->minDistance || priority[moveTo]->minDistance>rightVal->minDistance)
            {
                /*If the value in the left subtree is lesser than the value in the right subtree, we swap node with left child and similarly in the other case*/ 
                if(leftVal->minDistance<=rightVal->minDistance)
                {
                /* Make sure node locations are updated and then swap*/
                nodeLocations[priority[moveTo]->nodeIndex]=2*moveTo+1;
                nodeLocations[priority[2*moveTo+1]->nodeIndex]=moveTo;

                swap(moveTo, 2*moveTo+1);
                moveTo=2*moveTo+1;
                }
                else
                {
                /* Make sure node locations are updated and then swap*/
                nodeLocations[priority[moveTo]->nodeIndex]=2*moveTo+2;
                nodeLocations[priority[2*moveTo+2]->nodeIndex]=moveTo;

                swap(moveTo, 2*moveTo+2);
                moveTo=2*moveTo+2;
                }

                /*Note that it won't be a problem if the children aren't in the array- then leftVal and rightVal will hold INF */
                /* leftVal and rightVal store the values stored in the left and right subtrees if they exist, or INF if not */
                leftVal= (2*moveTo+1)>=last ? new HeapNode(-1, INF) : priority[2*moveTo+1];
                rightVal= (2*moveTo+2)>=last ? new HeapNode(-1, INF) : priority[2*moveTo+2];
            }

            return out;
        }

        /*===================================================================================
        *  Function: decreaseKey
        *  Functionality: decreases minDistance of specified node and reorganizes the array
        *  Input: None
        *  Output: None
        * ==================================================================================*/
        void decreaseKey(NodeType ind, WeightType dist)
        {
            int goTo=nodeLocations[ind];
            priority[goTo]->minDistance=dist;

            /* While value is lesser than value at parent node, go up the tree */
            while(goTo>0 && priority[goTo]->minDistance<priority[(goTo-1)/2]->minDistance)
            {
                /* Make sure node location is updated */
                nodeLocations[priority[(goTo-1)/2]->nodeIndex]=goTo;
                /* Move the element up the tree */
                swap(goTo, (goTo-1)/2);
                /* Make the index equal to the index of the parent node */
                goTo=(goTo-1)/2;
                /* Make sure node location is updated */
                nodeLocations[ind]=goTo;
            }
        }

        int empty();
        void printHeap();
    private:
        /*===================================================================
        *  Function: swap
        *  Functionality: swaps elements at different positions in array
        *  Input: Positions of swap
        *  Output: None
        * ==================================================================*/
        void swap(int p1, int p2)
        {
            /* Check if the positions are valid */
            if(p1<0 || p1>=last || p2<0 || p2>=last)
                return;
            HeapNode* temp=priority[p1];
            priority[p1]=priority[p2];
            priority[p2]=temp;
        }
};

/*===================================================================
 *  Function: empty
 *  Functionality: checks if heap is empty
 *  Input: None
 *  Output: None
 * ==================================================================*/
int MinHeap::empty()
{
    return last==0;
}

/*===================================================================
 *  Function: printHeap
 *  Functionality: prints level order traversal of tree
 *  Input: None
 *  Output: None
 * ==================================================================*/
void MinHeap::printHeap()
{
    for(int i=0; i<last; i++)
        cout<<nodeLocations[priority[i]->nodeIndex]<<" ";
    if(last==0)
        cout<<"EMPTY HEAP";
    cout<<"\n";
}

int main()
{
  /* Create the heap */
  MinHeap holder(100);

  /* Read in the inputs */
  int n;
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++)
    cin>>a[i];

  /* Add inputs to heap */
  for(int i=0; i<n; i++)
  {
    holder.insertHeap(i, a[i]);
    //holder.printHeap();
  }

  holder.decreaseKey(0, 1);

  /* Delete elements from heap based on priority */
  for(int i=0; i<n; i++)
  {
    cout<<(a[i]=holder.deleteRoot()->nodeIndex)<<"\n";
    //holder.printHeap();
  }

  /* Print the sorted array */
  for(int i=0; i<n; i++)
    cout<<a[i]<<" ";
  cout<<"\n";
}