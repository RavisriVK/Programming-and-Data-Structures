#include<iostream>
using namespace std;

typedef struct NODE {
    int value;
    struct NODE *next;
} node;

typedef node* Position;

class List {
    public:
        List();
        void insertValue(int val,  Position p);
        void deleteValue(Position p);
        void printList();
        int retrieveValue(Position p);
        Position end();
        Position first();
        Position next(Position p);
    private:
        Position head;
        Position tail;
};

List::List() {
    head=new node;
    tail=head;
    head->next=NULL;
}

void List::insertValue(int val,  Position p) {
    Position hold=p->next;
    p->next=new node;
    p->next->value=val;
    p->next->next=hold;
    if(hold==NULL)
        tail=p->next;
}

void List::deleteValue(Position p) {
    Position del=p->next;
    p->next=p->next->next;
    if(p->next->next==NULL)
        tail=p;
    delete del;
}

void List::printList() {
    for(Position i=head; i->next!=NULL; i=i->next)
        printf("%d ",i->next->value);
    printf("\n");
}

int List::retrieveValue(Position p) {
    return p->next->value;
}

Position List::end() {
    return tail;
}

Position List::first() {
    return head;
}

Position List::next(Position p) {
    return p->next;
}

int maxElement(List A) {
    Position p=A.first();
    int maxValue=A.retrieveValue(p);
    for(p=A.next(p); p!=A.end(); p=A.next(p))
        maxValue=(maxValue<A.retrieveValue(p))?A.retrieveValue(p):maxValue;
    return maxValue;
}

bool findElement(List A, int key) {
    for(Position i=A.first(); i!=A.end(); i=A.next(i))
        if(A.retrieveValue(i)==key)
            return true;
    return false;
}

int main() {
    List A;
    int n, element;
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%d",&element);
        A.insertValue(element, A.end());
    }
    A.printList();
    printf("Max: %d\n",maxElement(A));
    int k;
    scanf("%d",&k);
    printf("Found: %d\n",findElement(A,k));

}