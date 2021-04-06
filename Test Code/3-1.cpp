#include<iostream>
#include<list>
using namespace std;

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

    if(l2.back()>l1.size())
    {
        cout<<"Invalid Input\n";
        return 0;
    }

    list<int>::iterator i1=l1.begin();
    int prevIndex=0;
    while(!l2.empty())
    {
        int inc=l2.front()-prevIndex;
        prevIndex+=inc;
        l2.pop_front();

        for(int i=1; i<inc; i++)
            i1++;

        cout<<*i1<<" ";
        i1++;
    }
    cout<<"\n";
    return 0;
}