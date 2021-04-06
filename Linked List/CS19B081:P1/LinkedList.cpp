#include<iostream>

#include "LinkedList.h"

using namespace std;

void List::makeNull() 
{
    listHead = new CellNode;
    listHead->next = NULL;
}

void List::insert(ElementType val,  Position p) {
  Position temp;
  temp = p->next;
  p->next = new CellType;
  p->next->next  = temp;
  p->next->value = val;
  
}

ElementType List::retrieveValue(Position p) {
  return(p->next->value);  
}

void List::printList() 
{
    Position p;
    p = listHead->next;
    
    if(p == NULL)
        cout<<"EMPTY LIST\n";
    else
    {
        while (p != NULL)
        {
            cout<<p->value.coefficient<<" "<<p->value.degree<<" ";
            p = p->next;
        }
        cout << endl;
    }
    
 }

bool List::isZero() 
{
    for(Position p = listHead->next; p; p=p->next)
        if(p->value.coefficient!=0)
            return false;
    return true;  
 }

Position List::end() 
{
    Position p;
    p = listHead;
    while (p->next != NULL)
        p = p->next;
    return(p);
}

Position List::first() 
{
    return(listHead);
}

Position List::next(Position p) 
{
    return (p->next);
}

List PolynomialAdd(List A, List B)
{
    List C;
    C.makeNull();
    Position first=A.first();
    Position second=B.first();
    while(first->next && second->next) {
        if(A.retrieveValue(first).degree==B.retrieveValue(second).degree) {
            ElementType temp;
            temp.coefficient=A.retrieveValue(first).coefficient+B.retrieveValue(second).coefficient;
            if(temp.coefficient!=0) {
                temp.degree=A.retrieveValue(first).degree;
                C.insert(temp,C.end());
            }
            first=first->next;
            second=second->next;
        } else if(A.retrieveValue(first).degree>B.retrieveValue(second).degree) {
            if(A.retrieveValue(first).coefficient!=0)
                C.insert(A.retrieveValue(first),C.end());
            first=first->next;
        } else {
            if(B.retrieveValue(second).coefficient!=0)
                C.insert(B.retrieveValue(second),C.end());
            second=second->next;
        }
    }
    while(first->next) {
        if(A.retrieveValue(first).coefficient!=0)
            C.insert(A.retrieveValue(first),C.end());
        first=first->next;
    }
    while(second->next) {
        if(B.retrieveValue(second).coefficient!=0)
            C.insert(B.retrieveValue(second),C.end());
        second=second->next;
    }
      return C;
}
List PolynomialSubtract(List A, List B)
{
    List C;
    C.makeNull();
    Position first=A.first();
    Position second=B.first();
    while(first->next && second->next) {
        if(A.retrieveValue(first).degree==B.retrieveValue(second).degree) {
            ElementType temp;
            temp.coefficient=A.retrieveValue(first).coefficient-B.retrieveValue(second).coefficient;
            temp.degree=A.retrieveValue(first).degree;
            if(temp.coefficient!=0)
                C.insert(temp,C.end());
            first=first->next;
            second=second->next;
        } else if(A.retrieveValue(first).degree>B.retrieveValue(second).degree) {
            if(A.retrieveValue(first).coefficient!=0)
                C.insert(A.retrieveValue(first),C.end());
            first=first->next;
        } else {
            ElementType temp;
            temp.coefficient=(-1)*B.retrieveValue(second).coefficient;
            temp.degree=B.retrieveValue(second).degree;
            if(B.retrieveValue(second).coefficient!=0)
                C.insert(temp,C.end());
            second=second->next;
        }
    }
    while(first->next) {
        if(A.retrieveValue(first).coefficient!=0)
            C.insert(A.retrieveValue(first),C.end());
        first=first->next;
    }
    while(second->next) {
        ElementType temp;
        temp.coefficient=(-1)*B.retrieveValue(second).coefficient;
        temp.degree=B.retrieveValue(second).degree;
        if(B.retrieveValue(second).coefficient!=0)
            C.insert(temp,C.end());
        second=second->next;
    }
      return C;
}