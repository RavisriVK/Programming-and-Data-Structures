#include<iostream>
using namespace std;

struct node {
    int value;
    node* left;
    node* right;
    node(int val=0, node* lft=NULL, node* rgt=NULL): value(val), left(lft), right(rgt) {}
};

bool isSimilar(node* t1, node* t2)
{
    if(t1==NULL && t2==NULL)
        return true;
    if(t1==NULL || t2==NULL)
        return false;
    return isSimilar(t1->left, t2->left) && isSimilar(t1->right, t2->right);
}

int main()
{
    node* t1=new node(1);
    node* t2=new node(3);
    node* t3=new node(4);
    node* t4=new node(5);
    t1->left=t2;
    t1->right=t3;
    t3->left=t4;

    node* f1=new node(1);
    node* f2=new node(3);
    node* f3=new node(4);
    node* f4=new node(5);
    f1->left=t2;
    f1->right=t3;
    f3->left=t4;

    cout<<isSimilar(t1, f1)<<"\n";
}