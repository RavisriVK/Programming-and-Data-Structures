typedef struct ElementType {
  int coefficient;
  int degree;
} PolyNode;


typedef struct CellType* Position;

typedef struct CellType {
    ElementType value;
    Position next;
} CellNode;

class List {
    public:
        void makeNull();
        void insert(ElementType val,  Position p);
        void delItem(Position p);
        void printList();
        bool isZero();
        ElementType retrieveValue(Position p);
        Position end();
        Position first();
        Position next(Position p);
    private:
        Position listHead;
};

List PolynomialAdd(List A, List B);
List PolynomialSubtract(List A, List B);