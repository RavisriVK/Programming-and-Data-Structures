#include<stdio.h>
#include<string.h>

int main() {
    char s[10001];
    scanf("%s",s);
    int n=strlen(s);
    int ones=0;
    for(int i=0; i<n; i++)
        if(s[i]=='1')
            ones++;
    for(int i=0; i<n-ones; i++)
        printf("0");
    for(int i=0; i<ones; i++)
        printf("1");
    printf("\n");
}