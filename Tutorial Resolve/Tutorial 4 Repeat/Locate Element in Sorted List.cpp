#include<iostream>
#include<list>
using namespace std;

int findPosition(list<int>& l, int element)
{
    int position=0;
    for(list<int>::iterator i=l.begin(); i!=l.end() && *i<=element; i++) {
        if(*i==element)
            return position;
        position++;
    }
    return -1;
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
    int k;
    cin>>k;
    cout<<(findPosition(l, k)+1)<<"\n";
}