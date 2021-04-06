#include<iostream>
#include<queue>
#include<list>
#include<vector>
using namespace std;

#define INF (1.0/0.0)

struct vertex {
    int identifier;
    double cost;

    vertex(int id=-1, double cst=-1): identifier(id), cost(cst) {}
    bool operator<(vertex other) {
        return this->cost<other.cost;
    }
    bool operator<=(vertex other) {
        return this->cost<=other.cost;
    }
    bool operator>(vertex other) {
        return this->cost>other.cost;
    }
    bool operator>=(vertex other) {
        return this->cost>=other.cost;
    }
};

template<typename Object>
class MinHeap {
    public:
        int N;
        int last;
        vector<int> position;
        vector<Object*> array;
    public:
        MinHeap(int size) {
            N=size;
            last=0;
            array.reserve(size);
            position.reserve(size);
            for(int i=0; i<size; i++) {
                position[i]=-1;
                array[i]=nullptr;
            }
        }
        void push(int identifier, double cost) {
            int moveTo=last++;
            array[moveTo]=new Object(identifier, cost);
            while(moveTo>0 && *array[moveTo]<*array[(moveTo-1)/2]) {
                position[array[(moveTo-1)/2]->identifier]=moveTo;
                swap(array[moveTo], array[(moveTo-1)/2]);
                moveTo=(moveTo-1)/2;
            }
            position[array[moveTo]->identifier]=moveTo;
            cout.flush();
        }
        Object* pop() {
            return remove(array[0]->identifier);
        }
        Object* remove(int deleteIdentifier) {
            Object* toDelete=array[position[deleteIdentifier]];
            array[position[deleteIdentifier]]=array[--last];
            int moveTo=position[deleteIdentifier];
            while( (2*moveTo+1<last && *array[moveTo]>*array[2*moveTo+1]) || (2*moveTo+2<last && *array[moveTo]>*array[2*moveTo+2]) ) {
                if(2*moveTo+2>=last || *array[2*moveTo+1]<=*array[2*moveTo+2]) {
                    position[array[2*moveTo+1]->identifier]=moveTo;
                    swap(array[moveTo], array[2*moveTo+1]);
                    moveTo=2*moveTo+1;
                } else {
                    position[array[2*moveTo+2]->identifier]=moveTo;
                    swap(array[moveTo], array[2*moveTo+2]);
                    moveTo=2*moveTo+2;
                }
            }
            position[array[moveTo]->identifier]=moveTo;
            position[toDelete->identifier]=-1;
            array[last]=nullptr;
            return toDelete;
        }
        void decrease(int identifier, double cost) {
            int moveTo=position[identifier];
            array[moveTo]->cost=cost;
            while(moveTo>0 && *array[moveTo]<*array[(moveTo-1)/2]) {
                position[array[(moveTo-1)/2]->identifier]=moveTo;
                swap(array[moveTo], array[(moveTo-1)/2]);
                moveTo=(moveTo-1)/2;
            }
            position[array[moveTo]->identifier]=moveTo;
        }
};


int main() {
    int v, e;
    cin>>v>>e;
    typedef pair<double, int> pdi;
    vector< list<pdi> > AdjList(v);
    MinHeap<vertex> m(v);

    int in1, in2;
    double in3;
    for(int i=0; i<e; i++) {
        cin>>in1>>in2>>in3;
        AdjList[in1-1].push_back(pdi(in3, in2-1));
        AdjList[in2-1].push_back(pdi(in3, in1-1));
    }

    vector<bool> partition(v);
    vector<bool> inMinHeap(v);
    vector<bool> inS(v);
    vector<int> cuts(v); vector<double> cutV(v);
    for(int i=0; i<v; i++) {
        inS[i]=inMinHeap[i]=false;
        cuts[i]=-1; cutV[i]=INF;
    }
    partition[0]=true;
    inS[0]=true;

    for(list<pdi>::iterator i=AdjList[0].begin(); i!=AdjList[0].end(); i++) {
        m.push((*i).second, (*i).first);
        inMinHeap[(*i).second]=true;
        cuts[(*i).second]=0; cutV[(*i).second]=(*i).first;
    }


    int S=1;
    while(S<v) {
        vertex* temp=m.pop();
        int index=temp->identifier;
        inS[index]=true;
        for(list<pdi>::const_iterator i=AdjList[temp->identifier].begin(); i!=AdjList[temp->identifier].end(); i++) {
            if(inS[(*i).second]) continue;
            if(inMinHeap[(*i).second] && cutV[(*i).second]>(*i).first) {
                cuts[(*i).second]=temp->identifier;
                cutV[(*i).second]=(*i).first;
                m.decrease((*i).second,(*i).first);
            } else if(!inMinHeap[(*i).second]) {
                inMinHeap[(*i).second]=true;
                cuts[(*i).second]=temp->identifier;
                cutV[(*i).second]=(*i).first;
                m.push((*i).second, (*i).first);
            }
        }
        S++;
    }
    for(int i=1; i<v; i++) {
        if(cuts[i]!=-1) {
            cout<<cuts[i]<<" "<<i<<" "<<cutV[i]<<"\n";
        }
    }
    
}