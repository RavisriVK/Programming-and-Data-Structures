#include<iostream>
using namespace std;

struct node {
    int value;
    node* leftMostChild;
    node* rightSibling;
    node(int val=0, node* left=NULL, node* right=NULL): value(val), leftMostChild(left), rightSibling(right) {}
};

class Tree {
    public:
        Tree(node* root) {
            this->root=root;
        }
        int nodeHeight(node* vertex) {
            if(vertex==NULL)
                return -1;
            int height=0;
            for(node* i=vertex->leftMostChild; i!=NULL; i=i->rightSibling)
                height=max(height, 1+nodeHeight(i));
            return height;
        }
        int height() {
            return nodeHeight(root);
        }
    private:
        node* root;
};

int main() {
    node* n1=new node(1, NULL, NULL);
    node* n2=new node(2, NULL, n1);
    node* n3=new node(3, n2, NULL);
    node* n4=new node(4, NULL, n3);
    node* n5=new node(5, n4, NULL);
    node* n6=new node(6, NULL, NULL);
    node* n7=new node(7, NULL, n6);
    node* n8=new node(8, n7, n5);
    node* n9=new node(9, NULL, n8);
    node* root=new node(10, n9, NULL);
    Tree t(root);
    cout<<(t.height())<<"\n";
}