/*
ID: jgwilso1
PROG: agrinet
LANG: C++                 
*/
#include <iostream>
#include <cstdio>
using namespace std;
const int mxN = 105, INF = 1e6;
int adj[mxN][mxN], visit[mxN];
int t;
int main() {
    freopen("agrinet.in", "r", stdin);
    freopen("agrinet.out", "w", stdout);
    int n;
    cin >> n;
    for(int i=1; i<=n; ++i)
      for(int j=1; j<=n; ++j)
        cin >> adj[i][j];
    visit[1]=true;
    for(int i=1; i<=n-1; ++i){ //O(n^2) prim's (greedy)
      int I=-1, minI=INF;
      for(int j=1; j<=n; ++j){
        if(visit[j]){
          for(int k=1; k<=n; ++k){
            if(!visit[k]&&adj[j][k]<minI){
              minI=adj[j][k];
              I=k;
            }
          }
        }
      }
      t+=minI;
      visit[I]=true;
    }
    cout << t << endl;
    return 0;
}
