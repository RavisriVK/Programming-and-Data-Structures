#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack <char> s;
    int c;
    int isIncorrect=0;
    while((c=getchar())!='\n') {
        switch(c) {
            case '{':
            case '(':
            case '[': 
                    s.push(c); break;
            case '}': 
                    if(s.top()=='{') 
                        s.pop();
                    else 
                        isIncorrect=1;
                    break;
            case ')': 
                    if(s.top()=='(') 
                        s.pop();
                    else 
                        isIncorrect=1;
                    break;
            case ']': 
                    if(s.top()=='[') 
                        s.pop();
                    else 
                        isIncorrect=1;
                    break;
        }
    }
    printf("isIncorrect=%d\n",isIncorrect);
}