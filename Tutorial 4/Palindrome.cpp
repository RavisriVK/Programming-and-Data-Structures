#include<iostream>
#include<stack>

using namespace std;

int main() {
    int N;
    cin>>N;

    stack <char> s;

    int c;
    for(int i=0; i<N/2; i++) {
        c=getchar();
        s.push(c);
    }
    if(N%2==1)
        c=getchar();
    for(int i=0; i<N/2; i++) {
        c=getchar();
        if(s.top()!=c) {
            printf("Not a palindrome\n");
            return 0;
        } else {
            s.pop();
        }
    }
    printf("Palindrome\n");
    return 0;
}