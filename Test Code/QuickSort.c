#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int ReadIntegerArray(int *array)
{
    int delimiter=' ';
    int element;
    int count=0;

    while(delimiter!='\n')
    {
        scanf("%d", &element);
        array[count++]=element;

        while((delimiter=getc(stdin))==' ')
            ;
        ungetc(delimiter, stdin);
    }
    return count;
}

void QuickSort(int *a, int low, int high)
{
    if(low>=high)
        return;

    int i,j;
    int pivot=a[high];

    for(i=j=low; j<high; j++)
    {
        if(a[j]<pivot)
        {
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i++;
        }
    }
    int temp=a[i];
    a[i]=pivot;
    a[high]=temp;

    QuickSort(a,low,i-1);
    QuickSort(a,i+1,high);
}

int main()
{
    int a[100];
    int n=ReadIntegerArray(a);
    QuickSort(a,0,n-1);
    for(int i=0; i<n; i++)
        printf("%d ",a[i]);
    printf("\n");
}