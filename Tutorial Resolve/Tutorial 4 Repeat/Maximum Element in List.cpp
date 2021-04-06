#include<iostream>
#include<list>
using namespace std;

int findMax(const list<int>& l) {
    int maxElement=l.back();
    for(list<int>::const_iterator i=l.begin(); i!=l.end(); i++)
        maxElement=max(maxElement, *i);
    return maxElement;
}

int main()
{
    int n;
    cin>>n;
    list<int> l;
    int in;
    for(int i=0; i<n; i++) {
        cin>>in;
        l.push_back(in);
    }
    cout<<(findMax(l))<<"\n";
}