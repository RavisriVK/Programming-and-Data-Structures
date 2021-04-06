#include<stdio.h>

#define BOUNDARY 100123

int check(int p) {
    if(p>=BOUNDARY)
        return 1;
    else 
        return 0;
}

int findBoundary() {
    int low=0, high=1;
    while(check(high)==0) {
        low=high;
        high*=2;
    }
    int middle=(low+high)/2;
    while(low<=high) {
        if(check(middle)==0) {
            low=middle+1;
        } else if(check(middle-1)==1) {
            high=middle-1;
        } else {
            break;
        }
        middle=(low+high)/2;
    }
    return middle;
}

int main() {
    printf("%d\n",findBoundary());
}