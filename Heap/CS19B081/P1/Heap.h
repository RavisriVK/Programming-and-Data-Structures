/* This is the predefined size of the internal array */
#define HEAP_SIZE 1000

typedef int ElementType;
typedef int Position;

/* The class Heap defines an ADT Heap. */
class Heap {
  private:
    ElementType priority[HEAP_SIZE];        // A Heap of integers
    Position last;
  public:
    void insertHeap(ElementType x);         // Inserts an element on to the Heap
    ElementType deleteRoot();               // DeleteRoot of the Heap
    int empty();                            // returns 1 if Heap is empty
    void createHeap();                      // creates an empty Heap
    void printHeap();                       // Prints the heap
  private:
    void swap(Position p1, Position p2);    // Swaps elements at two positions- only for use internally
 };