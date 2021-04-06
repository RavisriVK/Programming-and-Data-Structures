#include<iostream>
using namespace std;

typedef struct NODE {
    int data;
    struct NODE* left;
    struct NODE* right;
} node;

class Tree {
    public:
        Tree();
        int nodeHeight(node *);
        int treeHeight();
        void setRoot(node *);
        node* newNode(int);
        bool isSimilar(Tree);
        bool isSimilar(node *, node *);
    private:
        node *root;
};

Tree::Tree() {
    root=NULL;
}

int Tree::treeHeight() {
    return nodeHeight(root);
}

int Tree::nodeHeight(node *vertex) {
    if(vertex==NULL)
        return -1;
    else
        return 1+max(nodeHeight(vertex->left), nodeHeight(vertex->right));
}

void Tree::setRoot(node *root) {
    this->root=root;
}

node* Tree::newNode(int data) {
    node *out=new node;
    out->data=data;
    out->left=out->right=NULL;
    return out;
}

bool Tree::isSimilar(Tree second) {
    return isSimilar(root, second.root);
}

bool Tree::isSimilar(node *first, node *second) {
    if(first==NULL && second==NULL) {
        return true;
    } else if(first!=NULL && second!=NULL) {
        if(isSimilar(first->left, second->left)==false)
            return false;
        if(isSimilar(first->right, second->right)==false)
            return false;
        return true;
    } else{
        return false;
    }
}

int main() {
    Tree t;
    node *a=t.newNode(1);
    node *b=t.newNode(2);
    node *c=t.newNode(3);
    node *d=t.newNode(4);
    node *e=t.newNode(5);
    node *f=t.newNode(6);
    node *g=t.newNode(7);
    node *h=t.newNode(8);
    node *i=t.newNode(9);
    node *j=t.newNode(10);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    d->left=f;
    d->right=g;
    f->left=h;
    h->left=i;
    i->left=j;
    t.setRoot(a);

    Tree T;
    node *A=T.newNode(1);
    node *B=T.newNode(2);
    node *C=T.newNode(3);
    node *D=T.newNode(4);
    node *E=T.newNode(5);
    node *F=T.newNode(6);
    node *G=T.newNode(7);
    node *H=T.newNode(8);
    node *I=T.newNode(9);
    node *J=T.newNode(10);
    A->left=B;
    A->right=C;
    B->left=D;
    B->right=E;
    D->left=F;
    D->right=G;
    F->left=H;
    H->left=I;
    I->left=J;
    T.setRoot(A);
    
    if(t.isSimilar(T))
        cout << "True\n";
    else 
        cout << "False\n";
    //cout << t.isSimilar(T) << "\n";
}