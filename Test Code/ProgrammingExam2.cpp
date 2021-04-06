#include <iostream>
#include "string.h"
using namespace std;
typedef int elementType;
typedef int Position;
typedef struct CellType {
  elementType value;
  Position next;
} CellNode;
class List {
public:
  void insert(elementType x, Position p);
  void delItem(Position p);
  void makeNull();
  void printList();
  elementType retrieve (Position p);
  Position end();
  Position first();
  Position next(Position p);
  bool isEmpty();
private:
  Position lastNode;
  CellNode*  list;
};

void List::makeNull() {
  list = new CellNode[101]; 
  lastNode = 0;
}

bool List::isEmpty(){
    if(lastNode == 0)
      return true;
    return false;
}
void List::insert(elementType x, Position p) {
  int i;
  for (i = lastNode+1; i > p; i--)
    list[i] = list[i-1];
  list[p].value = x;
  lastNode++;
}
elementType List::retrieve(Position p) {
  return(list[p].value);
}
void List::printList() {
  Position p;
  p = 1;
  while (p <= lastNode) {
    cout << list[p].value;
    p++;
  }
  cout << "\n";
 }
Position List::end() {
  Position p;
  p = lastNode + 1;
  return(p);
}
void List::delItem(Position p) {
  int i;
  for (i = p; i < lastNode; i++)
    list[i] = list[i+1];
  lastNode = lastNode - 1;
}
Position List::first() {
  return(1);
}
Position List::next(Position p) {
  return (p+1);
}

/****************************
   Completed This Function!
******************************/
List  BigIntSubtract(char *string1, char *string2) {
    /*===========================================================================================================
     * The best method involving lists is the simple pen and paper method- subtract digit by
     * digit, taking into consideration previous borrows, and propagating borrow when necessary
     *
     *      digit[i]= (num1[i]-num2[i]-borrow)      if non-negative=> in this case borrow for next didgit is 0
     *      digit[i]= (num1[i]-num2[i]-borrow)+10   otherwise=> in this case, borrow for next digit is 1
     *==========================================================================================================*/
    /* Obtain the length of the two strings */
    int length1=strlen(string1);
    int length2=strlen(string2);

    /* Convert each string to a list representing that number */
    List number1;
    number1.makeNull();
    for(Position i=1; i<=length1; i++)
        number1.insert(string1[i-1]-'0', number1.end());

    List number2;
    number2.makeNull();
    for(Position i=1; i<=length2; i++)
        number2.insert(string2[i-1]-'0', number2.end());

    /* Obtaining pointers to the end of the lists */
    Position pointer1=number1.end()-1;
    Position pointer2=number2.end()-1;

    /* This is the output list which stores the difference */
    List out;
    out.makeNull();

    /* This variable holds the borrow element while performing subtraction */
    elementType borrow=0;

    /* We subtract digit by digit while neither list has been exhausted */
    while(pointer1>=number1.first() && pointer2>=number2.first()) 
    {
        /* Here we obtain the prospective next digit */
        elementType nextDigit= (number1.retrieve(pointer1) - borrow) - number2.retrieve(pointer2);

        /* We check if we need to borrow again- if so, we need to add 10 to 'nextDigit' */
        if(nextDigit>=0)
        {
            out.insert(nextDigit, out.first());
            borrow=0;
        }
        else
        {
            out.insert(10+nextDigit, out.first());
            borrow=1;
        }

        /* We decrement both position variables */
        pointer1--;
        pointer2--;
    }

    /* Here, we have exhausted all the digits in the second list (number) */
    while(pointer1>=number1.first())
    {
        /* We can take the digit in the second number corresponding to the given digit in the first list to be zero */
        elementType nextDigit= (number1.retrieve(pointer1) - borrow);

        /* The condition to check whether we need to borrow or not remains the same */
        if(nextDigit>=0)
        {
            out.insert(nextDigit, out.first());
            borrow=0;
        }
        else
        {
            out.insert(10+nextDigit, out.first());
            borrow=1;
        }

        /* Decrementing the position variable */
        pointer1--;
    }

    /* Here we remove any extraneous zeroes */
    while(!out.isEmpty() && out.retrieve(out.first())==0)
        out.delItem(out.first());
    if(out.isEmpty())
        out.insert(0,out.first());

    return out;
}

int main(){
    
  int testCases;
  char string1[101], string2[101];
  List result;
  cin>>testCases;
  while(testCases--)
  {
    cin >> string1;
    cin >> string2;
    
    result = (List) BigIntSubtract(string1, string2);
    cout<<string1<<" - "<<string2<<" = ";
    result.printList();
  }
  return 0;
}