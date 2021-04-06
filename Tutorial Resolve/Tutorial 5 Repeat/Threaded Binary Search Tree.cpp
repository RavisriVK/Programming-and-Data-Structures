#include<iostream>
using namespace std;

template<typename Object>
class BST {
    private:
        struct Node {
            Object key;
            Node* left;
            Node* right;
            bool rightThread;
            bool leftThread;
            Node(const Object& k=Object(), Node* lft=NULL, Node* rgt=NULL, bool tlft=false, bool trgt=false):  key(k), left(lft), right(rgt), leftThread(tlft), rightThread(trgt) {}
        };
    public:
        BST(): root(NULL) {}

        void insertKey(const Object& x) {
            Node *parent=NULL, *traverser=root;
            while(traverser!=NULL)
            {
                if(traverser->key==x) return;
                parent=traverser;
                if(x<traverser->key) traverser=(traverser->leftThread) ? NULL : traverser->left;
                else if(x>traverser->key) traverser=(traverser->rightThread) ? NULL : traverser->right;
            }
            if(parent==NULL) {
                root=new Node(x, NULL, NULL, true, true);
            } else if(x<parent->key) {
                parent->leftThread=false;
                parent->left=new Node(x, parent->left, parent, true, true);
            } else {
                parent->rightThread=false;
                parent->right=new Node(x, parent, parent->right, true, true);
            }
        }

        bool findKey(const Object& x) {
            for(Node* traverser=root; traverser!=NULL; )
            {
                if(traverser->key==x) return true;
                if(x<traverser->key)
                    traverser=(traverser->leftThread) ? NULL : traverser->left;
                else if(x>traverser->key)
                    traverser=(traverser->rightThread) ? NULL : traverser->right;
            }
            return false;
        }

        void deleteKey(const Object& x) {
            Node *parent=NULL, *traverser=root;
            while(traverser!=NULL)
            {
                if(traverser->key==x) break;
                parent=traverser;
                if(x<traverser->key) traverser=(traverser->leftThread) ? NULL : traverser->left;
                else if(x>traverser->key) traverser=(traverser->rightThread) ? NULL : traverser->right;
            }

            if(traverser==NULL) return;

            if(traverser->leftThread && traverser->rightThread) {
                if(parent==NULL) {
                    root=NULL;
                } else if(x<parent->key) {
                    parent->leftThread=true;
                    parent->left=traverser->left;
                } else {
                    parent->rightThread=true;
                    parent->right=traverser->right;
                } 
            } else if(!traverser->leftThread && traverser->rightThread) {
                Node* temp=rightmost(traverser->left);
                temp->right=traverser->right;
                if(parent==NULL)
                    root=root->left;
                else if(x<parent->key)
                    parent->left=traverser->left;
                else if(x>parent->key)
                    parent->right=traverser->left;
            } else if(traverser->leftThread && !traverser->rightThread) {
                Node* temp=leftmost(traverser->right);
                temp->left=traverser->left;
                if(parent==NULL)
                    root=root->right;
                else if(x<parent->key)
                    parent->left=traverser->right;
                else if(x>parent->key)
                    parent->right=traverser->right;
            } else {
                Node* leftGreatest=rightmost(traverser->left);
                Node* rightLeast=leftmost(traverser->right);
                leftGreatest->rightThread=false;
                leftGreatest->right=traverser->right;
                rightLeast->left=leftGreatest;
                if(parent==NULL)
                    root=root->left;
                else if(x<parent->key)
                    parent->left=traverser->left;
                else if(x>parent->key)
                    parent->right=traverser->left;
            }

            delete traverser;
        }

        void inOrderTraversal() {
            Node* start=leftmost(root);
            int i=15;
            while(start!=NULL && i>0) {
                cout<<start->key<<" ";
                if(start->rightThread) {
                    start=start->right;
                } else {
                    start=leftmost(start->right);
                }
                i--;
            }
            cout<<"\n";
        }

        void printTree()
        {
            printTreeBackend(root, false, "", -1, false);
        }


    private:
        Node* leftmost(Node* vertex) {
            if(vertex==NULL) return NULL;
            for( ; !vertex->leftThread; vertex=vertex->left)
                if(vertex->left==NULL) {cout<<"SSS"<<vertex->leftThread<<" "<<vertex->key<<"EEE\n}"; return NULL;}
            return vertex;
        }

        Node* rightmost(Node* vertex) {
            if(vertex==NULL) return NULL;
            for( ; !vertex->rightThread; vertex=vertex->right)
                if(vertex->right==NULL) {cout<<"SSS"<<vertex->rightThread<<" "<<vertex->key<<"EEE\n}"; return NULL;}
            return vertex;
        }

        void printTreeBackend(Node* root, bool isRight, string prefix, Object to, bool thread)
        {
            if(root != NULL){
                cout << prefix;
                cout << (isRight ? "├── " : "└── ") << root->key << endl;
                printTreeBackend((root->rightThread?NULL:root->right), true, prefix + (isRight ? "│   " : "    "), ((root->right==NULL)?(-1):(root->right->key)), root->rightThread);
                printTreeBackend((root->leftThread?NULL:root->left), false, prefix + (isRight ? "│   " : "    "),  ((root->left==NULL)?(-1):(root->left->key)), root->leftThread);
            }
            if(root == NULL && thread){
                cout << prefix;
                string s1="├── NULL=>"+to_string(to);
                string s2="├── NULL=>"+to_string(to);
                cout << (isRight ? s1 : s2) << endl;
            }
        }

    private:
        Node* root;
};

int main() {
    BST<int> t;
    while(true) {
        char op;
        cin>>op;
        if(op=='i') {
            int in; cin>>in;
            t.insertKey(in);
        } else if(op=='d') {
            int in; cin>>in;
            t.deleteKey(in);
        } else if(op=='f') {
            int in; cin>>in;
            if(t.findKey(in)) cout<<"Found\n";
            else cout<<"Not Found\n";
        } else if(op=='p') {
            t.printTree();
        } else if(op=='t') {
            t.inOrderTraversal();
        } else {
            break;
        }
    }
}