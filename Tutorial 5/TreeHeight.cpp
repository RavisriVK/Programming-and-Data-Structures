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

int main() {
    Tree t;
    node *a=t.newNode(1);
    node *b=t.newNode(1);
    node *c=t.newNode(1);
    node *d=t.newNode(1);
    node *e=t.newNode(1);
    node *f=t.newNode(1);
    node *g=t.newNode(1);
    node *h=t.newNode(1);
    node *i=t.newNode(1);
    node *j=t.newNode(1);
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
}







































/*#include <iostream>
using namespace std;

typedef int ElemType;

class Node {
    public:
        void addChild(Node *);
    private:
        ElemType data;
        Node *left;
        Node *right;
        friend class Tree;
};

void Node::addChild(Node *child) {
    if(left==NULL) {
        left=child;
    } else if(right==NULL) {
        right=child;
    }
}

class Tree {
    public:
        Tree():root(NULL) { }
        int nodeHeight(Node *);
        int treeHeight();
        Node* createNode(ElemType);
        void setRoot(Node *);
    private:
        Node* root;
};

void Tree::setRoot(Node *root) {
    this->root=root;
}

int Tree::nodeHeight(Node* node) {
    if(node==NULL)
        return -1;
    else
        return 1 + max(nodeHeight(node->left), nodeHeight(node->right));
}

int Tree::treeHeight() {
    return nodeHeight(root);
}

Node* Tree::createNode(ElemType data) {
    Node *newNode= new Node;
    newNode->data=data;
    newNode->left= newNode->right= NULL;
    return newNode;
}

int main() {
    Tree tree;
    Node* A=tree.createNode(1);
    Node* B=tree.createNode(1);
    Node* C=tree.createNode(1);
    Node* D=tree.createNode(1);
    Node* E=tree.createNode(1);
    Node* F=tree.createNode(1);
    Node* G=tree.createNode(1);
    Node* H=tree.createNode(1);
    Node* I=tree.createNode(1);
    Node* J=tree.createNode(1);
    tree.setRoot(A);

    A->addChild(B);
    A->addChild(C);
    B->addChild(D);
    B->addChild(E);
    D->addChild(F);
    F->addChild(G);
    C->addChild(H);
    C->addChild(I);
    D->addChild(J);

    printf("%d\n",tree.treeHeight());
}*/