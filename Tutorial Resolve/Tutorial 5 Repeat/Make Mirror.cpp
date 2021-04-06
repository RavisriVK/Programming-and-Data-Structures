#include<iostream>
using namespace std;

struct node {
    int value;
    node* left;
    node* right;
    node(int val=0, node* lft=NULL, node* rgt=NULL): value(val), left(lft), right(rgt) {}
};

void mirror(node* t)
{
    if(t==NULL)
        return;
    mirror(t->left);
    mirror(t->right);
    node* temp=t->left;
    t->left=t->right;
    t->right=temp;
}

void print(node* t) {
    if(t==NULL) return ;
    cout<<t->value<<" "<<((t->left!=NULL)?t->left->value:-1)<<" "<<((t->right!=NULL)?t->right->value:-1)<<"\n";
    print(t->left);
    print(t->right);
}

int main()
{
    node* t1=new node(1);
    node* t2=new node(2);
    node* t3=new node(3);
    node* t4=new node(4);
    t1->left=t2;
    t1->right=t3;
    t3->left=t4;

    print(t1);
    mirror(t1);
    print(t1);
}