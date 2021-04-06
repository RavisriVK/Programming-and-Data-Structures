#include<iostream>
using namespace std;

int HashFunction(string s, int m) {
    int prime=101;
    int n=s.length();
    int power=1;
    int ans=0;
    for(int i=0; i<n; i++) {
        ans+=s[i]*power;
        power*=prime;
    }
    return ans%m;
}

int main() {
    cout<<(HashFunction("Hello World", 200))<<"\n";
    cout<<(HashFunction("CS2700", 200))<<"\n";
}