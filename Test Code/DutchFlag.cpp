#include<iostream>
using namespace std;

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

void swap(int *a, int i, int j)
{
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}

int main()
{
    int a[100];
    int n=ReadIntegerArray(a);
    int i=0, j=n-1;

    for(int k=i; k<=j; k=max(k+1, i))
    {
        if(a[k]==0)
            swap(a, k--, i++);
        else if(a[k]==2)
            swap(a, k--, j--);
    }
    for(int k=0; k<n; k++)
        printf("%d ",a[k]);
    printf("\n");
} 