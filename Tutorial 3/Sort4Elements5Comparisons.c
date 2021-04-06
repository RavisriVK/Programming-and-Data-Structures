#include<stdio.h>

int main() {
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    int alpha, beta, gamma, delta;

    /* This is a form of insertion sort */
    /* 1 comparison */
    if(a<b) {
        alpha=a;
        beta=b;
    } else {
        alpha=b;
        beta=a;
    }

    /* Max 2 comparisons */
    if(c<alpha) {
        gamma=beta;
        beta=alpha;
        alpha=c;
    } else if(c<beta) {
        gamma=beta;
        beta=c;
    } else {
        gamma=c;
    }

    /* 2 comparisons */
    if(d<beta) {
        if(d>alpha) {
            delta=gamma;
            gamma=beta;
            beta=d;
        } else {
            delta=gamma;
            gamma=beta;
            beta=alpha;
            alpha=d;
        }
    } else {
        if(d>gamma) {
            delta=d;
        } else {
            delta=gamma;
            gamma=d;
        }
    }

    printf("%d %d %d %d\n",alpha,beta,gamma,delta);

}