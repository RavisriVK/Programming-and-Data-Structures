#include <iostream>

#include "ListByArray.h"

using namespace std;

void Print (ElementType x) {
  cout << x.coefficient<< " " << x.degree<< " ";
}
 

void List::makeNull() {
  list = new CellNode[10000]; 
  lastNode = 0;
}
void List::insert(ElementType val, Position p) {
  Position temp;
  int i;
  for (i = lastNode+1; i > p; i--)
    list[i] = list[i-1];
  list[p].value = val;
  lastNode++;
}
void List::printList() {
  Position p;
  p = 1;
  if(lastNode == 0){
    cout<<"EMPTY LIST\n";
    return ;
  }
  while (p <= lastNode) {
    Print (list[p].value);
    p++;
  }
  cout << "\n";
}


Position List::end() {
  Position p;
  p = lastNode + 1;
  return(p);
}

Position List::first() {
  return(1);
}

Position List::next(Position p) {
  return (p+1);
}

ElementType List::retrieveValue(Position p) {
  return (list[p].value);
}

List PolynomialAdd(List A, List B)
{
    List C;
    C.makeNull();
    Position first=A.first();
    Position second=B.first();
    while(first<A.end() && second<B.end()) {
        if(A.retrieveValue(first).degree==B.retrieveValue(second).degree) {
            ElementType temp;
            temp.coefficient=A.retrieveValue(first).coefficient+B.retrieveValue(second).coefficient;
            if(temp.coefficient!=0) {
                temp.degree=A.retrieveValue(first).degree;
                C.insert(temp,C.end());
            }
            first++;
            second++;
        } else if(A.retrieveValue(first).degree>B.retrieveValue(second).degree) {
            if(A.retrieveValue(first).coefficient!=0)
                C.insert(A.retrieveValue(first),C.end());
            first++;
        } else {
            if(B.retrieveValue(second).coefficient!=0)
                C.insert(B.retrieveValue(second),C.end());
            second++;
        }
    }
    while(first<A.end()) {
        if(A.retrieveValue(first).coefficient!=0)
            C.insert(A.retrieveValue(first),C.end());
        first++;
    }
    while(second<B.end()) {
        if(B.retrieveValue(second).coefficient!=0)
            C.insert(B.retrieveValue(second),C.end());
        second++;
    }
      return C;
}
List PolynomialSubtract(List A, List B)
{
    List C;
    C.makeNull();
    Position first=A.first();
    Position second=B.first();
    while(first<A.end() && second<B.end()) {
        if(A.retrieveValue(first).degree==B.retrieveValue(second).degree) {
            ElementType temp;
            temp.coefficient=A.retrieveValue(first).coefficient-B.retrieveValue(second).coefficient;
            temp.degree=A.retrieveValue(first).degree;
            if(temp.coefficient!=0)
                C.insert(temp,C.end());
            first++;
            second++;
        } else if(A.retrieveValue(first).degree>B.retrieveValue(second).degree) {
            if(A.retrieveValue(first).coefficient!=0)
                C.insert(A.retrieveValue(first),C.end());
            first++;
        } else {
            ElementType temp;
            temp.coefficient=(-1)*B.retrieveValue(second).coefficient;
            temp.degree=B.retrieveValue(second).degree;
            if(B.retrieveValue(second).coefficient!=0)
                C.insert(temp,C.end());
            second++;
        }
    }
    while(first<A.end()) {
        if(A.retrieveValue(first).coefficient!=0)
            C.insert(A.retrieveValue(first),C.end());
        first++;
    }
    while(second<B.end()) {
        ElementType temp;
        temp.coefficient=(-1)*B.retrieveValue(second).coefficient;
        temp.degree=B.retrieveValue(second).degree;
        if(B.retrieveValue(second).coefficient!=0)
            C.insert(temp,C.end());
        second++;
    }
      return C;
}