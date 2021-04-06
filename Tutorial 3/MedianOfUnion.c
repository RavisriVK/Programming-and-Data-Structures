#include<stdio.h>
#include<stdlib.h>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

int cmp(const void *a, const void *b) {
    return (*(int*)a)-(*(int*)b);
}

int kthUnion(int *a, int *b, int n, int k) {
    int low=MAX(0,k-n-1), high=MIN(k-1,n-1);
    int middle=(low+high)/2;
    while(low<=high) {
        if( ((k-1-middle>=n) || a[middle]<=b[k-1-middle]) && (k<=(middle+1) || a[middle]>=b[k-2-middle]) ) {
            return a[middle];
        } else if(a[middle]>b[k-1-middle]) {
            high=middle-1;
        } else {
            low=middle+1;
        }
        middle=(low+high)/2;
    }
    low=MAX(0,k-n-1);
    high=MIN(k-1,n-1);
    middle=(low+high)/2;
    while(low<=high) {
        if( ((k-1-middle>=n) || b[middle]<=a[k-1-middle]) && ((k-2-middle<0) || b[middle]>=a[k-2-middle]) ) {
            return b[middle];
        } else if(b[middle]>a[k-1-middle]) {
            high=middle-1;
        } else {
            low=middle+1;
        }
        middle=(low+high)/2;
    }
    return -1;
}

int main() {
    int n;
    scanf("%d",&n);
    int c[2*n];
    int a[n];
    for(int i=0; i<n; i++) {
        scanf("%d",&a[i]);
        c[i]=a[i];
    }
    int b[n];
    for(int i=0; i<n; i++) {
        scanf("%d",&b[i]);
        c[n+i]=b[i];
    }
    qsort(c,2*n, sizeof(int), cmp);
    
    for(int i=0; i<2*n; i++)
        printf("%d ",c[i]);
    printf("\n");
    double median=((double)(kthUnion(a,b,n,n) + kthUnion(a,b,n,n+1)))/2.0;
    printf("Median: %.1lf\n",median);

    printf("Index k: ");
    int k;
    scanf("%d",&k);
    int kth=kthUnion(a,b,n,k);
    printf("Kth element: %d \n",kth);
}