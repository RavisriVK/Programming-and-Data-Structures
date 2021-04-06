#include<stdio.h>

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

int ternarySearch(int *a, int n, int k) {
    int low=0, high=n-1;
    int m1=(2*low+high)/3, m2=(low+2*high)/3;
    while(low<=high) {
        if(k<a[m1]) {
            high=m1-1;
        } else if(k>a[m2]) {
            low=m2+1;
        } else if(k==a[m1]) {
            return (1+m1);
        } else if(k==a[m2]) {
            return (1+m2);
        } else {
            low=m1+1;
            high=m2-1;
        }
        m1=(2*low+high)/3;
        m2=(low+2*high)/3;
    }
    return -1;
}

int recursiveTernarySearch(int *a, int n, int k) {
    int low=0, high=n-1;
    int m1=(2*low+high)/3, m2=(low+2*high)/3;
    while(low<=high) {
        if(k<a[m1]) {
            high=m1-1;
        } else if(k>a[m2]) {
            low=m2+1;
        } else if(k==a[m1]) {
            return (1+m1);
        } else if(k==a[m2]) {
            return (1+m2);
        } else {
            low=m1+1;
            high=m2-1;
        }
        int l=recursiveTernarySearch(a+low, high+1-low, k);
        if(l!=-1)
            return low+l;
        else 
            return l;
    }
    return -1;
}

int main() {
    int a[100];
    int n=ReadIntegerArray(a);
    int k;
    scanf("%d",&k);
    printf("%d %d\n", ternarySearch(a,n,k), recursiveTernarySearch(a,n,k));
}