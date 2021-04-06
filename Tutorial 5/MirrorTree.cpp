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
        void takeMirror(node *);
        void makeMirror();
        void printTree(node *);
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

void Tree::takeMirror(node *vertex) {
    if(vertex!=NULL) {
        takeMirror(vertex->left);
        takeMirror(vertex->right);
        node *temp=vertex->left;
        vertex->left=vertex->right;
        vertex->right=temp;
    }
}

void Tree::makeMirror() {
    takeMirror(root);
}

void Tree::printTree(node *vertex) {
    if(vertex!=NULL) {
        printf("%d=>",vertex->data);
        int f1=0, f2=0;
        if(vertex->left==NULL) {
            printf("-1 ");
        } else {
            printf("%d ", vertex->left->data);
            f1=1;
        }
        if(vertex->right==NULL) {
            printf("-1 ");
        } else {
            printf("%d ", vertex->right->data);
            f2=1;
        }
        printf("\n");
        if(f1) printTree(vertex->left);
        if(f2) printTree(vertex->right);
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
    printf("%d\n",t.treeHeight());
    t.makeMirror();
    t.printTree(a);
}