#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

using namespace std;

ElemType stack::Top() {

  if (tos < STACK_SIZE)
    return (stackArray[tos]);
  else
    return(0);
  }

int stack::Empty() {

  if (tos >= STACK_SIZE)
	 return 1;
  else
	 return 0;
}

void stack::Push(ElemType x) {

  tos--;
  stackArray[tos] = x;
}

ElemType stack::Pop() {

  ElemType tmp;

  if (tos >= STACK_SIZE) 
    return (-1); 
  else {
    tmp = stackArray[tos];
    tos++;
    return (tmp);
  }
}

void stack::MakeNull() {

  tos = STACK_SIZE;

}
/* end {Implementation of stack} */

int EvaluatePostFix(char **postFixExpr, int exprLength) {
    int result; 

    stack holder;
    holder.MakeNull();
    /*Here, we keep adding numerical inputs to the stack, and if we encounter an operator we perform the relevant operation on the last two elements in the stack*/
    for(int i=0; i<exprLength; i++) {
        if(strcmp(postFixExpr[i], "+")==0) {
            int op1=holder.Pop();
            int op2=holder.Pop();
            holder.Push(op1+op2);
        } else if(strcmp(postFixExpr[i], "-")==0) {
            int op1=holder.Pop();
            int op2=holder.Pop();
            holder.Push(op2-op1);
        } else if(strcmp(postFixExpr[i], "*")==0) {
            int op1=holder.Pop();
            int op2=holder.Pop();
            holder.Push(op1*op2);
        } else if(strcmp(postFixExpr[i], "/")==0) {
            int op1=holder.Pop();
            int op2=holder.Pop();
            holder.Push(op2/op1);
        } else if(strcmp(postFixExpr[i], "%")==0) {
            int op1=holder.Pop();
            int op2=holder.Pop();
            holder.Push(op2%op1);
        } else {
            holder.Push(atoi(postFixExpr[i]));
        }
    }
    result=holder.Pop();
    return result;
}
