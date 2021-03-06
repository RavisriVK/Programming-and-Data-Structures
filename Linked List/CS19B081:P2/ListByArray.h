typedef struct ElementType {
  int coefficient;
  int degree;
} PolyNode;

void Print (ElementType x);

typedef int Position;
typedef struct CellType {
  ElementType value;
  Position next;
} CellNode;

class List {
public:
  void insert(ElementType val, Position p);
  ElementType retrieveValue(Position p);
  void makeNull();
  void printList();
  Position end();
  Position first();
  Position next(Position p);
private:
  Position lastNode;
  CellNode*  list;
};

List PolynomialAdd(List A, List B);
List PolynomialSubtract(List A, List B);