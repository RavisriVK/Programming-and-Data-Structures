#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;


int main()
{
    int delimiter=' ';
    vector<string> out;
    stack<string> op;
    string element;

    unordered_map<string, int> priority;
    priority.insert(pair<string, int>("+", 0));
    priority.insert(pair<string, int>("-", 0));
    priority.insert(pair<string, int>("*", 1));
    priority.insert(pair<string, int>("/", 1));
    priority.insert(pair<string, int>("%", 1));

    while(delimiter!='\n')
    {
        cin>>element;

        if( element.back()>='0' && element.back()<='9' )
        {
            out.push_back(element);
        }
        else 
        {
            while( !op.empty() && priority.at(element)<=priority.at(op.top()) )
            {
                out.push_back(op.top());
                op.pop();
            }
            op.push(element);
        }

        while((delimiter=getc(stdin))==' ')
            ;
        ungetc(delimiter,stdin);
    }

    while(!op.empty()) {
        out.push_back(op.top());
        op.pop();
    }

    for(vector<string>::iterator it=out.begin(); it!=out.end(); it++)
        cout<<(*it)<<" ";
    cout<<"\n";
}