#include <iostream>
#include <string>
#include "HashTable.h"
using namespace std;

int main() {
    /* Creating a new hashtable */
    HashTable myTable;
    myTable.MakeHashTable(2);

    /* Reading in n */
    int n;
    cin >> n;

    /* Performing the relevant operations */
    for(int i=0; i<n; i++) {
        /* Option input*/
        int option;
        cin >> option;
        string input;
        if(option!=4)
            /* Taking key string input as necessary */
            cin >> input;
            
        if(option==1) {
            myTable.HashTableInsert(input, DataGenerator(input));
        } else if(option==2) {
            ElementType check=myTable.HashTableFind(input);
            if(check.consonantCount==0 && check.vowelCount==0) 
                cout << "Not Found\n";
            else 
                cout << "Consonants: " << check.consonantCount << " Vowels: " << check.vowelCount << "\n";
        } else if(option==3) {
            myTable.HashTableDelete(input);
        } else {
            myTable.PrintSizeAndCapacity();
        }
    } 
    return 0;
}