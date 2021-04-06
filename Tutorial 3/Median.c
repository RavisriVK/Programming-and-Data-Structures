#include<bits/stdc++.h>
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

void Print(int *a, int low, int high) {
    for(int i=low; i<=high; i++)
        printf("%d ",a[i]);
    printf("\n");
}

int kthSmallest(int* a, int low, int high, int k) {
    if(low>high) return -1;
    int pivot=a[high];
    int i=low;
    for(int j=low; j<high; j++)
        if(a[j]<pivot)
            swap(a[i++], a[j]);
    swap(a[i], a[high]);

    if((i-low)==k-1)
        return pivot;
    else if((i-low)>=k)
        return kthSmallest(a, low, i-1, k);
    else
        return kthSmallest(a, i+1, high, k-(i+1-low));
}

int Kth(int *a, int low, int high, int k) {
    if(low>high)
        return -1;

    int pivot=a[high];
    int i,j;
    for(i=j=low; j<=high; j++) {
        if(a[j]<pivot) {
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i++;
        }
    }
    int temp=a[i];
    a[i]=pivot;
    a[high]=temp;

    //Print(a,low,high);

    if((i-low)==k) {
        return pivot;
    } else if((i-low)>k) {
        return Kth(a, low, i-1, k);
    } else {
        return Kth(a, i+1, high, k-(i+1-low));
    }
}

int main() {
    int a[100];
    int n=ReadIntegerArray(a);
    double median;
    if(n%2==1)
        median=Kth(a,0,n-1,n/2);
    else
        median=(Kth(a,0,n-1,n/2-1)+Kth(a,0,n-1,n/2))/2.0;
    printf("%.1lf\n",median);
}