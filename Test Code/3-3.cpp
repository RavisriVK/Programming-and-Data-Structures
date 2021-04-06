#include<iostream>
#include<list>

using namespace std;

template<typename Iterator, typename Object>
Iterator Find(Iterator start, Iterator end, const Object& x)
{
    for(Iterator i=start; i!=end; i++)
        if(*i==x)
            return i;
    return end;
}

int main()
{
    list<int> l;

    int delimiter=' ';
    int element;
    while(delimiter!='\n')
    {
        cin>>element;
        l.push_back(element);

        while((delimiter=getc(stdin))==' ')
            ;
        ungetc(delimiter,stdin);
    }

    cin >> element;
    cout<<((l.end()!=Find<list<int>::iterator,int>(l.begin(), l.end(), element))?"found":"not found")<<"\n";
}