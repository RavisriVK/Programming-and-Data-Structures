#include<iostream>
#include<algorithm>

#include "List.h"

using namespace std;

void List::makeNull() {
    list = new elementType[100000]; 
    lastNode = 0;
}
void List::insert(elementType x, Position p) {
    int i;
    for (i = lastNode+1; i > p; i--)
        list[i] = list[i-1];
    list[p] = x;
    lastNode++;
}
void List::printList() {
    Position p;
    p = 1;

    while (p <= lastNode) {
        cout << list[p] << " ";
        p++;
    }

    if(lastNode==0)
        cout << "$";
    
    cout << "\n";
}
void List::sort() {
    std::sort(list, list + lastNode + 1);
}
Position List::end() {
    Position p;
    p = lastNode + 1;
    return(p);
}
void List::delItem(Position p) {
    int i;
    for (i = p; i < lastNode; i++)
        list[i] = list[i+1];
    lastNode = lastNode - 1;
}
Position List::first() {
    return(1);
}
Position List::next(Position p) {
    return (p+1);
}

elementType List::retrieve (Position p) {
    return (list[p]);
}

List Union(List A, List B) {
    List C;
    C.makeNull();

    /*Here, we insert all unique elements of the first list*/
    for(Position i=A.first(); i!=A.end(); i=A.next(i)) {
        elementType current=A.retrieve(i);
        Position j;
        /*Check that it hasn't been added before...*/
        for(j=C.first(); j!=C.end() && C.retrieve(j)!=current; j=C.next(j))
            ;
        if(j==C.end())
            C.insert(current, C.end());
    }
    
    /*Here we add all unique elements of the second list that haven't been added before*/
    for(Position i=B.first(); i!=B.end(); i=B.next(i)) {
        elementType current=B.retrieve(i);
        Position j;
        /*Check that it hasn't been added before...*/
        for(j=C.first(); j!=C.end() && C.retrieve(j)!=current; j=C.next(j))
            ;
        if(j==C.end())
            C.insert(current, C.end());
    }

    return C;
}

List Intersection(List A, List B) {
    List C;
    C.makeNull();

    /*We add all elements common to both A and B and which haven't been added before*/
    for(Position i=A.first(); i!=A.end(); i=A.next(i)) {
        elementType current=A.retrieve(i);
        Position j;
        /*Here we make sure 'current' is present in B as well*/
        for(j=B.first(); j!=B.end() && B.retrieve(j)!=current; j=B.next(j))
            ;
        Position k;
        /*Here we make sure 'current' wasn't previously added*/
        for(k=C.first(); k!=C.end() && C.retrieve(k)!=current; k=C.next(k))
            ;
        if(j!=B.end() && k==C.end())
            C.insert(current, C.end());
    }

    return C;
}