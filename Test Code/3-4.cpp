#include<iostream>
#include<list>
using namespace std;

template<typename Object>
list<Object> intersection(list<Object> a, list<Object> b)
{
    list<Object> out;
    typename list<Object>::iterator checkFrom=b.begin();
    typename list<Object>::iterator i=a.begin();
    while(i!=a.end() && checkFrom!=b.end())
    {
        if(*i>*checkFrom)
            checkFrom++;
        else if(*i==*checkFrom)
            out.push_back(*i++);
        else 
            i++;
    }
    return out;
}

int main()
{
    list<int> l1, l2;

    int delimiter=' ';
    int element;
    while(delimiter!='\n')
    {
        cin>>element;
        l1.push_back(element);

        while((delimiter=getc(stdin))==' ')
            ;
        ungetc(delimiter,stdin);
    }
    delimiter=' ';
    while(delimiter!='\n')
    {
        cin>>element;
        l2.push_back(element);

        while((delimiter=getc(stdin))==' ')
            ;
        ungetc(delimiter,stdin);
    }

    list<int> c=intersection<int>(l1,l2);
    for(list<int>::iterator i=c.begin(); i!=c.end(); i++)
        cout<<*i<< " ";
    cout<<"\n";

    return 0;
}