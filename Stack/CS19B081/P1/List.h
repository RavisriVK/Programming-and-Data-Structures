typedef int elementType;
typedef int Position;

class List {
public:
    void insert(elementType x, Position p);
    void delItem(Position p);
    void makeNull();
    void printList();
    void sort();
    Position end();
    Position first();
    Position next(Position p);
    elementType retrieve(Position p);
private:
    Position lastNode;
    elementType*  list;
};

List Union(List A, List B);
List Intersection(List A, List B);