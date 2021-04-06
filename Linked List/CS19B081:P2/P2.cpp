#include <iostream>

#include "ListByArray.h"

using namespace std;

int main() {
     
      List A, B, C, D;

      /* Read two polynomial using the given ADT and perform the Addition and Subtraction */
    int n, m;
    cin>>n>>m;

    ElementType input;

    A.makeNull();
    for(int i=0; i<n; i++) {
        cin>>input.coefficient>>input.degree;
        A.insert(input, A.end());
    }

    B.makeNull();
    for(int i=0; i<m; i++) {
        cin>>input.coefficient>>input.degree;
        B.insert(input, B.end());
    }
      
      C = (List) PolynomialAdd (A, B);
    C.printList();
    
      D = (List) PolynomialSubtract (A, B);
    D.printList();

    return 0;
}