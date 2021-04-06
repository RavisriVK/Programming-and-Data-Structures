#include<stdio.h>

int main() {
    int y=0,n=0,m=0;

    int delimiter=' ';
    char element[10];

    while(delimiter!='\n')
    {
        scanf("%s", element);

        if(element[0]=='Y')
            y++;
        else if(element[0]=='N')
            n++;
        else 
            m++;

        while((delimiter=getc(stdin))==' ')
            ;
        ungetc(delimiter,stdin);
    }
    for(int i=0; i<n; i++)
        printf("No ");
    for(int i=0; i<n; i++)
        printf("Maybe ");
    for(int i=0; i<n; i++)
        printf("Yes ");
    printf("\n");
}