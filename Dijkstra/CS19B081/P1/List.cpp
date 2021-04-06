#include "List.h"

/* Initializes head and tail pointers */
List::List()
{
    head=new listNode;
    tail=head;
    head->next=NULL;
}

/* Inserts an element at the end of the list */
void List::pushBack(ElementType val)
{
    tail->next=new listNode(val, NULL);
    tail=tail->next;
}
/* Retrieves the data stored at a Position */
ElementType List::retrieveValue(Position p) 
{
    return p->next->data;
}
/* Returns a pointer to the end of the list */
Position List::end() 
{
    return tail;
}
/* Returns a pointer to the beginning of the list */
Position List::first() 
{
    return head;
}
/* Returns a pointer to the node just after the given one */
Position List::next(Position p) 
{
    return p->next;
}
