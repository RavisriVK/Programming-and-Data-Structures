#include<stdio.h>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

int ReadIntegerArray(int *array)
{
    int delimiter=' ';
    int element;
    int count=0;

    while(delimiter!='\n')
    {
        scanf("%d", &element);

        array[count]=element;
        count++;

        while((delimiter=getc(stdin))==' ')
            ;
        ungetc(delimiter,stdin);
    }
    return count;
}

void Print(int *array, int size) {
    for(int i=0; i<size; i++)
        printf("%d ",array[i]);
    printf("\n");
}


void insert(int *array, int firstUnsortedPortion) {
    int low=0, high=firstUnsortedPortion-1;
    int middle=(low+high)/2;
    int element=array[firstUnsortedPortion];

    while(low<=high) {
        middle=(low+high)/2;
        if(element<array[middle]) {
            high=middle-1;
        } else {
            low=middle+1;
        }
    }
    int insertAt=element<=array[middle]?middle-1:middle;

    for(int i=firstUnsortedPortion; i>(insertAt+1) && i>0; i--)
        array[i]=array[i-1];
    array[insertAt+1]=element;
}

void insertionSort(int *array, int size) {
    for(int i=0; i<size; i++)
        insert(array, i);
}

int main()
{
    int a[100];
    int n=ReadIntegerArray(a);
    insertionSort(a,n);
    Print(a, n);
}