#include<iostream>
#include<list>
using namespace std;

template<typename Object>
list<Object> unionLists(list<Object> a, list<Object> b)
{
    list<Object> out;
    typename list<Object>::iterator i1=a.begin();
    typename list<Object>::iterator i2=b.begin();
    while(i1!=a.end() || i2!=b.end())
    {
        if((i2==b.end() && i1!=a.end()) || (i2!=b.end() && i1!=a.end() && *i1<*i2))
        {
            out.push_back(*i1);
            i1++;
        }
        else if((i2!=b.end() && i1==a.end()) || (i2!=b.end() && i1!=a.end() && *i1>*i2))
        {
            out.push_back(*i2);
            i2++;
        } 
        else 
        {
            out.push_back(*i1);
            i1++; i2++;
        }
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

    list<int> c=unionLists<int>(l1,l2);
    for(list<int>::iterator i=c.begin(); i!=c.end(); i++)
        cout<<*i<< " ";
    cout<<"\n";

    return 0;
}