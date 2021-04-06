#include<iostream>
using namespace std;

// Prints the k-Length subsets of the set a from index begin to end(both inclusive), prints prefix string s before printing a subset
// s subset1
// s subset2
// .....
void kLength(string s, char *a, int begin, int end, int k){
    if(k==0){
        s.pop_back();
        cout << s+'}' << endl;
        return;
    }
    for(int i=begin; i<end-k+2; i++){
        s = s + a[i] + ",";
        kLength(s,a,i+1,end,k-1);
        s.pop_back();
        s.pop_back();
    }
}
int main(){
    char *a;
    cout << "Size of set: ";
    int n;
    cin >> n;
    a = new char[n];
    cout << "Input set:\n";
    for(int i=0; i<n; i++)
        cin >> a[i];
    cout << "\nSubsets are:\n";
    cout << "𝟇" << endl;
    for(int k=1; k<n+1; k++)
        kLength("{",a,0,n-1,k);
    return 0;
}
