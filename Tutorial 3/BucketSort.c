#include<stdio.h>

#define LOW 0
#define RANGE 1000

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


int main() {
    int a[100];
    int bucket[RANGE]={0};
    int n=ReadIntegerArray(a);
    for(int i=0; i<n; i++) {
        bucket[a[i]-LOW]++;
    }
    for(int i=0; i<RANGE; i++) {
        for(int j=0; j<bucket[i]; j++) {
            printf("%d ",(LOW+i));
        }
    }
    printf("\n");
}