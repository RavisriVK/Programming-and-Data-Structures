#include <iostream>
#include <string>
#include "HashTable.h"
using namespace std;

/*==================================================================================
 * Function: MakeHashTable
 * Input: integer value of the new capacity
 * Output: none
 * Functionality: Creates a new HashTable with a specified capacity 
 *==================================================================================*/
void HashTable::MakeHashTable(int newCapacity) {
    /* Allocating memory for the hashtable and boolean array */
    hashTable=new HashNode *[newCapacity];
    deleted=new bool[newCapacity];

    /* Initializing the hashtable and boolean array */
    for(int i=0; i<newCapacity; i++) {
        hashTable[i]=NULL;
        deleted[i]=false;
    }

    /* Initialzing capacity and size */
    capacity=newCapacity;
    size=0;
}

/*====================================================================================
 * Function: HashTableResize
 * Input: integer value of the new capacity
 * Output: none
 * Functionality: Copies the old hashtable into a new hashtable of specified capacity 
 *===================================================================================*/
void HashTable::HashTableResize(int newCapacity) {
    /* Freeing the 'deleted' array */
    delete[] deleted;

    /* Allocating memory for the new hashtable and boolean array */
    HashNode** newHashTable=new HashNode *[newCapacity];
    deleted=new bool[newCapacity];

    /* Initializing the hashtable and boolean array */
    for(int i=0; i<newCapacity; i++) {
        newHashTable[i]=NULL;
        deleted[i]=false;
    }

    /* Copying the nodes from the old hashtable to the new hashtable*/
    for(int i=0; i<capacity; i++) {
        /* Inserting an element in the old hashtable iff it isn't NULL */
        if(hashTable[i]!=NULL) {
            /* Finding a free position in the new hashtable */
            int index=HashCode(hashTable[i]->key, newCapacity);
            for(int j=0; j<newCapacity; j++) {
                if(newHashTable[index]==NULL) {
                    newHashTable[index]=hashTable[i];
                    break;
                }
                index=(index+1)%newCapacity;
            }
        }
    }

    /* Setting the new hashtable and capacity value */
    hashTable=newHashTable;
    capacity=newCapacity;
}

/*====================================================================================
 * Function: HashCode
 * Input: string from which hashcode is generated and modulo value
 * Output: non-negative integer less than modulo
 * Functionality: Generates hashcode from string 
 *===================================================================================*/
int HashTable::HashCode(string input, int modulo) {
    int hashValue=0;
    for(int i=0; i<input.length(); i++)
        hashValue+=input[i];
    return hashValue%modulo;
}

/*====================================================================================
 * Function: HashTableInsert
 * Input: the newKey and data pair to be inserted
 * Output: none
 * Functionality: Inserts the  newKey and data pair if it doesn't already exist
 *===================================================================================*/
void HashTable::HashTableInsert(string newKey, ElementType data) {
    /* This is the first index to start searching from */
    int index= HashCode(newKey, capacity);

    /* Here we find the first free spot to insert the key and data, while checking that the key isn't in the table */
    int i;
    for(i=0; i<capacity; i++) {
        if(hashTable[index]==NULL) {
            break;
        } else if(hashTable[index]->key.compare(newKey)==0) {
            return;
        }
        index= (index+1)%capacity;
    }

    /* Here we make sure that the key doesn't already exist in the array */
    /* If the key exists, it can only exist in the portion till the first node which is NULL and has not been deleted, by open addressing */
    int loop=index;
    for( ; i<capacity && !(hashTable[loop]==NULL && deleted[loop]==false); i++) {
        if(hashTable[loop]!=NULL && hashTable[loop]->key.compare(newKey)==0) {
            return;
        }
        loop=(loop+1)%capacity;
    }

    /* Here we insert the new node */
    hashTable[index]= new HashNode;
    hashTable[index]->key=newKey;
    hashTable[index]->data= data;

    /* We make sure that the capacity is proportionate to the size */
    size++;
    if(size>(capacity/2)) {
        HashTableResize(2*capacity);
    }
}

/*====================================================================================
 * Function: HashTableDelete
 * Input: the key to be removed from the table
 * Output: data (vowels, consonants) of the key, if found
 * Functionality: Deletes the key if it exists
 *===================================================================================*/
ElementType HashTable::HashTableDelete(string key) {
    /* If the key exists, it can only exist in the portion till the first node which is NULL and has not been deleted, by open addressing */
    /* If we find the key, we break the loop and hold the index */
    int index= HashCode(key, capacity);
    int i;
    for(i=0; i<capacity && !(hashTable[index]==NULL && deleted[index]==false); i++) {
        if(hashTable[index]!=NULL && hashTable[index]->key.compare(key)==0) 
            break;
        index= (index+1)%capacity;
    }

    /* If the key isn't found we return a dummy ElementType result */
    if(i>=capacity || (hashTable[index]==NULL && deleted[index]==false)) 
        return DataGenerator("");
    
    /*Here we delete the key from the table and make the deleted array reflect that*/
    ElementType output=hashTable[index]->data;
    delete hashTable[index];
    hashTable[index]=NULL;
    deleted[index]=true;

    /* We make sure that the capacity is proportionate to the size */
    size--;
    if(size<(capacity/4)) {
        HashTableResize(capacity/2);
    }
    return output;
}

/*====================================================================================
 * Function: HashTableFind
 * Input: the key to search for
 * Output: data (vowels, consonants) of the key, if found
 * Functionality: Finds a key in the table and returns its data
 *===================================================================================*/
ElementType HashTable::HashTableFind(string key) {
    /* If the key exists, it can only exist in the portion till the first node which is NULL and has not been deleted, by open addressing */
    int index= HashCode(key, capacity);
    for(int i=0; i<capacity && !(hashTable[index]==NULL && deleted[index]==false); i++) {
        if( hashTable[index]!=NULL && hashTable[index]->key.compare(key)==0) {
            return hashTable[index]->data;
        }
        index= (index+1)%capacity;
    }

    /* If the data hasn't already been returned, the key isn't in the table */
    return DataGenerator("");
}

/* Self explanatory */
void HashTable::PrintSizeAndCapacity() {
    cout << "size =" << size << " capacity =" << capacity << "\n";
}

/* Generates an 'ElementType with the number of consonants and vowels of a string */
ElementType DataGenerator(string input) {
    ElementType output;
    int vowels=0, consonants=0;
    for(int i=0; i<input.length(); i++) {
        int current= input[i];
        if(current=='a'||current=='e'||current=='i'||current=='o'||current=='u')
            vowels++;
        else 
            consonants++;
    }
    output.consonantCount=consonants;
    output.vowelCount=vowels;
    return output;
}