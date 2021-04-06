#include<iostream>
#include<list>
using namespace std;

#define INF (1.0/0.0)
typedef std::pair<int, double> heapnode;

class minheap {
    private:
        heapnode **priority;                             
        int *nodeLocations;
        int last;
    public:
        minheap(int size) {
            priority=new heapnode*[size];
            nodeLocations=new int[size];
            last=0;
            for(int i=0; i<size; i++) {
                priority[i]=NULL;
                nodeLocations[i]=-1;
            }
        }                            
        void insertHeap(int index, double cost) {
            int insertAt=last++;
            priority[insertAt]=new heapnode(index, cost);
            while(insertAt>0 && priority[insertAt]->second < priority[(insertAt-1)/2]->second) {
                nodeLocations[priority[(insertAt-1)/2]->first]=insertAt;
                swap(priority[insertAt], priority[(insertAt-1)/2]);
                insertAt=(insertAt-1)/2;
            }
            nodeLocations[index]=insertAt;

        }   
        heapnode* deleteRoot() {
            heapnode* root=priority[0];
            priority[0]=priority[--last];
            int moveTo=0;
            while( ((2*moveTo+1)<last && priority[moveTo]->second>priority[2*moveTo+1]->second) || ((2*moveTo+2)<last && priority[moveTo]->second>priority[2*moveTo+2]->second) ) {
                if((2*moveTo+2)>=last || priority[2*moveTo+1]->second<priority[2*moveTo+2]->second) {
                    nodeLocations[priority[2*moveTo+1]->first]=moveTo;
                    swap(priority[2*moveTo+1], priority[moveTo]);
                    moveTo=2*moveTo+1;
                } else {
                    nodeLocations[priority[2*moveTo+2]->first]=moveTo;
                    swap(priority[2*moveTo+2], priority[moveTo]);
                    moveTo=2*moveTo+2;
                }
            }
            nodeLocations[root->first]=-1;
            priority[last]=NULL;
            if(last>0)
                nodeLocations[priority[moveTo]->first]=moveTo;
            return root;
            
        }
        void decreaseKey(int index, double cost) {
            int moveTo=nodeLocations[index];
            if(priority[moveTo]->second<cost) return;
            priority[moveTo]->second=cost;
            while(moveTo>0 && priority[moveTo]->second < priority[(moveTo-1)/2]->second) {
                nodeLocations[priority[(moveTo-1)/2]->first]=moveTo;
                swap(priority[moveTo], priority[(moveTo-1)/2]);
                moveTo=(moveTo-1)/2;
            }
            nodeLocations[index]=moveTo;
        }
        bool present(int index) {
            return nodeLocations[index]!=-1;
        }
};

int main() {
    int n;
    cin>>n;

    minheap H(n);

    double d[n];
    for(int i=0; i<n; i++) d[i]=INF;
    d[0]=0;

    list<heapnode> A[n];
    int e;
    cin>>e;
    int in1, in2;
    double weight;
    for(int i=0; i<e; i++) {
        cin>>in1>>in2>>weight;
        A[in1].push_back(heapnode(in2, weight));
        A[in2].push_back(heapnode(in1, weight));
    }

    double minCost=0;

    for(int i=1; i<n; i++)
        H.insertHeap(i, d[i]);

    for(list<heapnode>::iterator i=A[0].begin(); i!=A[0].end(); i++)
        H.decreaseKey((*i).first, (*i).second);

    for(int i=1; i<n; i++) {
        heapnode* wNode=H.deleteRoot();
        cout<<wNode->second<<" ";
        int w=wNode->first;
        minCost+=wNode->second;
        for(list<heapnode>::iterator t=A[w].begin(); t!=A[w].end(); t++) {
            int v=(*t).first;
            int weight=(*t).second;
            if(H.present(v))
                H.decreaseKey(v, weight);
        }
    }
    cout<<"\n";
    cout<<minCost<<"\n";
}


