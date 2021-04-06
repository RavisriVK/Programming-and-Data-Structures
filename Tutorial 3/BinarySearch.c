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

int bsearch1(int *a, int n, int k) {
    int low=0, high=n-1;
    int middle=(low+high)/2;
    while(low<=high) {
        if(k<a[middle])
            high=middle-1;
        else if(k>a[middle])
            low=middle+1;
        else
            return (1+middle);
        middle=(low+high)/2;
    }
    return -1;
}

int bsearch2(int *a, int n, int k) {
    int low=0, high=n-1;
    int middle=(low+high)/2;
    while(low<(high-1)) {
        if(k<=a[middle])
            high=middle;
        else 
            low=middle;
        middle=(low+high)/2;
    }
	if(a[low]==k)
		return (1+low);
    else if(a[high]==k)
        return (1+high);
    else 
        return -1;
}

int bsearch3(int *a, int n, int k) {
    int low=0, high=n-1;
    int middle=(low+high+1)/2;
    while(low<=high) {
        if(k<a[middle])
            high=middle-1;
        else if(k>a[middle])
            low=middle+1;
        else 
            return (1+middle);
        middle=(low+high)/2;
    }
    return -1;
}

int main() {
    int a[100];
    int n=ReadIntegerArray(a);
    int k;
    scanf("%d",&k);
    printf("%d %d %d\n", bsearch1(a,n,k),bsearch2(a,n,k),bsearch3(a,n,k));
}
