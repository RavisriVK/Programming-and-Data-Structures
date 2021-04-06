o#include <iostream>
#include <string>
using namespace std;

/*==============================================
 * Structure: ElementType
 * Fields: 
 *      vowelCount- number of vowels
 *      consonantCount- number of consonants
 * ============================================*/
typedef struct {
    int vowelCount;
    int consonantCount;
} ElementType;

/*==============================================
 * Structure: HashNode
 * Fields: 
 *      key- string key
 *      data- number of consonants and vowels
 * ============================================*/
typedef struct {
    string key;
    ElementType data;
} HashNode;


class HashTable 
{
    public:
        void MakeHashTable(int);
        void HashTableResize(int);
        int HashCode(string, int);
        void HashTableInsert(string, ElementType);
        ElementType HashTableDelete(string);
        ElementType HashTableFind(string);
        void PrintSizeAndCapacity();

    private:
        /* Array of pointers to HashNodes */
        HashNode** hashTable;
        /* Array of booleans to check if node at an index has been deleted or not */
        bool *deleted;
        /* Self explanatory */
        int capacity;
        int size;
};

ElementType DataGenerator(string);