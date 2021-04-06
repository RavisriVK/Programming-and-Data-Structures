#define STACK_SIZE 1000
#define EXPR_LENGTH 1000
typedef  int ElemType;

using namespace std;
class stack {
  ElemType stackArray[STACK_SIZE];        // A stack of characters
  int tos;              // A pointer to the top of stack.

public :
  ElemType Top();               // returns the element on Top of the stack
  void Push(ElemType x);      // Pushes an element on to the stack
  ElemType Pop();             // Pops an element from the stack
  int Empty();            // returns 1 if stack is Empty
  void MakeNull();        // creates an Empty stack
 };

 int EvaluatePostFix(char **postFixExpr, int exprLength);