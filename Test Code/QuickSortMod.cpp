#include<iostream>
#include<algorithm>

void qsort(int *a, int low, int high)
{
    int i=low, j=high;
    int pivot=a[(low+high)/2];
    do {
        while(a[i]<pivot)
            i++;
        while(a[j]>pivot)
            j--;
        std::swap(a[i++], a[j--]);
    } while(i<=j);
    if(j>low)
        qsort(a, low, j);
    if(i<high)
        qsort(a, i, high);
}

int main()
{
    int a[6]={1,4,2,3,6,5};
    qsort(a, 0, 5);
    for(int i=0; i<6; i++)
        printf("%d ",a[i]);
    printf("\n");
}