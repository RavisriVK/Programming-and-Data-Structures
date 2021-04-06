#include<iostream>

template<typename Object>
class BST
{
    private:
        struct Node
        {
            Object key;
            Node* left;
            Node* right;

            Node(const Object& Key=Object()): key(Key), left(NULL), right(NULL)
                {}
        };

    public:
        BST(): root(NULL)
            {}

        void insertObject(Object& x)
        {
            Node *traverser=root, *parent=NULL;
            for( ; traverser!=NULL; traverser=(x<traverser->key ? traverser->left: traverser->right))
            {
                parent=traverser;
                if(traverser->key==x) return;
            }
            traverser=new Node(x);
            if(parent!=NULL)
                (x<parent->key? parent->left: parent->right)=traverser;
            else
                root=traverser;
        }

        bool findObject(Object& x)
        {
            for(Node* traverser=root; traverser!=NULL; traverser= (x < traverser->key ? traverser->left : traverser->right))
                if(x==traverser->key)
                    return true;

            return false;
        }

        void deleteObject(Object& x)
        {
            Node *traverser=root, *parent=NULL;
            for( ; traverser!=NULL && traverser->key!=x; traverser=( x<traverser->key ? traverser->left : traverser->right))
                parent=traverser;

            if(traverser!=NULL)
            {
                if(traverser->left!=NULL)
                {
                    Node* leftMax=traverser->left;
                    while(leftMax->right!=NULL)
                        leftMax=leftMax->right;
                    leftMax->right=traverser->right;
                }
                if(parent==NULL)
                {
                    if(root->left==NULL && root->right==NULL)
                        root=NULL;
                    else
                        root=(root->left!=NULL ? root->left : root->right);
                }
                else
                {
                    if(traverser->left==NULL && traverser->right==NULL)
                        (parent->left==traverser?parent->left:parent->right)=NULL;
                    else if(traverser->left!=NULL)
                        (parent->left==traverser? parent->left: parent->right)=traverser->left;
                    else
                        (parent->left==traverser?parent->left:parent->right)=traverser->right;
                }
                delete traverser;
            }
        }

        void printTree()
        {
            printTree(root, 0);
        }
    private:
        void printTree(Node* treeRoot, int spacing)
        {
            if(treeRoot!=NULL)
            {
                for(int i=0; i<spacing; i++)
                    std::cout<<"    ";
                std::cout << "|___" << treeRoot->key << "\n";
                printTree(treeRoot->right, spacing+1);
                printTree(treeRoot->left, spacing+1);
            }
        }

    private:
        Node* root;
};
