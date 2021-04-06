#include<iostream>
using namespace std;

void mergeTrees(int n, int t1[n][2], int m, int t2[m][2], int t[n+m+1][2]) {
    t[0][0]=0;
    t[0][1]=-1;
    int currentParent=0;
    int p1=0, p2=0, p=1;
    while(p1<n || p2<m) {
        if(p1<n && t1[p1][1]==currentParent) {
            t[p][0]=t1[p1][0];
            t[p][1]=currentParent;
            p1++;
        } else if(p2<n && t2[p2][1]==currentParent) {
            t[p][0]=t2[p2][0];
            t[p][1]=currentParent;
            p2++;
        } else {
            if(p1<n) {
                currentParent=t1[p1][1];
                t[p][0]=t1[p1][0];
                t[p][1]=currentParent;
                p1++;
            }
            else {
                currentParent=t2[p2][1];
                t[p][0]=t2[p2][0];
                t[p][1]=currentParent;
                p2++;
            }
        }
        p++;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    /*
        Tree representation:
            tree[0...n-1][0] -> nodes
            tree[0...n-1][1] -> parents of nodes
    */
    int t1[n][2];
    for(int i=0; i<n; i++)
        cin >> t1[i][0];
    for(int i=0; i<n; i++)
        cin >> t1[i][1];
    int t2[m][2];
    for(int i=0; i<m; i++)
        cin >> t2[i][0];
    for(int i=0; i<m; i++)
        cin >> t2[i][1];

    int t[n+m+1][2];
    mergeTrees(n, t1, m, t2, t);

    for(int i=0; i<n+m+1; i++)
        cout << t[i][0] << " ";
    cout << "\n";
    for(int i=0; i<n+m+1; i++)
        cout << t[i][1] << " ";
    cout << "\n";
}