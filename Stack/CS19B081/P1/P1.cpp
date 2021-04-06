#include <iostream>

#include "List.h"

using namespace std;

int main() {
  
    List A, B, C, D;
    elementType a1, a2;

    int M, N;
    cin>>M>>N;

    /*Taking in the list A*/
    A.makeNull();
    for(int i=0; i<M; i++) {
        cin>>a1;
        A.insert(a1, A.end());
    }

    /*Taking in the list B*/
    B.makeNull();
    for(int i=0; i<N; i++) {
        cin>>a2;
        B.insert(a2, B.end());
    }

    /*We find the union of A and B and sort before printing*/
    C=(List) Union(A,B);
    C.sort();
    C.printList();

    /*We find the intersection of A and B and sort before printing*/
    D=(List) Intersection(A,B);
    D.sort();
    D.printList();
}