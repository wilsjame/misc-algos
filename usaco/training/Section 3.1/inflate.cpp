/*
ID: jgwilso1
PROG: inflate
LANG: C++                 
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int v[10005], w[10005], dp[10005]; //dp[j] best value up to weight j, all items available
int main() {
    freopen("inflate.in", "r", stdin);
    freopen("inflate.out", "w", stdout);
    int m, n;
    cin >> m >> n;
    for(int i=0; i<n; ++i)
      cin >> v[i] >> w[i];
    for(int i=0; i<n; ++i)
      for(int j=0; j<=m; ++j)
        if(j-w[i]>=0)
          dp[j]=max(dp[j], dp[j-w[i]]+v[i]);
    cout << dp[m] << endl;
    return 0;
}
// unbounded 01 knapsack
// if 01 bounded iterate j from m to 0 to avoid double counting
