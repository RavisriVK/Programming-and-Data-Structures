#include <iostream>
#include <string.h>
#include <stdio.h>

#include "stack.h"

using namespace std;

int main() {
    /*n is the number of space seperated inputs*/
    int n;
    cin >> n;

    char *postFixExpr[n];

    /*This is a temperory variable to read a string and find its size*/
    char input[EXPR_LENGTH+1];

    /*Here we read in the expression and convert it to tokens*/
    for(int i=0; i<n; i++)
    {
        cin >> input;

        postFixExpr[i]=new char[strlen(input)+1];
        strcpy(postFixExpr[i], input);
    }

    for(int i=0; i<n; i++)
        cout << postFixExpr[i] << " ";
    int value = (int) EvaluatePostFix(postFixExpr, n);
    std::cout << "\nThe Result is :" << value << std::endl;
    return 0;
}