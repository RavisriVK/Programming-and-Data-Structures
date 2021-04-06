#include <iostream>
#include "Nodes.h"

/* This is a generic list ADT with limited operations */
class List 
{
    public:
        List();                                 /* Initializes head and tail pointers */
        void pushBack(ElementType val);         /* Inserts an element at the end of the list */
        ElementType retrieveValue(Position p);  /* Retrieves the data stored at a Position */
        Position end();                         /* Returns a pointer to the end of the list */
        Position first();                       /* Returns a pointer to the beginning of the list */
        Position next(Position p);              /* Returns a pointer to the node just after the given one */
    private:
        Position head;
        Position tail;
};
