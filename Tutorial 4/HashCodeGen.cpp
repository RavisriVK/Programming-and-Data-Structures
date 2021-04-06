#include<iostream>
#include<string.h>

unsigned m=50;
unsigned P=101;

unsigned int hashcode(char *s) {
    unsigned int n=strlen(s);
    unsigned int power=1;
    int hash=0;
    for(unsigned int i=0; i<n; i++) {
        hash+=s[i]*power;
        power*=P;
    }
    return hash%m;
}

int main() {
    char s1[]="Hello World";
    char s2[]="CS2700";
    printf("%d %d\n",hashcode(s1),hashcode(s2));
}