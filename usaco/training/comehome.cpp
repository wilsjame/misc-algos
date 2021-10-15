/*
ID: jgwilso1
PROG: comehome
LANG: C++                 
*/
#include <iostream>
#include <cstdio>
#include <cctype>
#include <utility>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int d[52][52];

int char2num(char c) {
  if (isupper(c))
    return c - 'A' + 26;
  else 
    return c - 'a';
}

int main() {
    freopen("comehome.in", "r", stdin);
    freopen("comehome.out", "w", stdout);
    int n;
    cin >> n;

    // seed
    for (int i = 0; i < 52; i++) {
      for (int j = 0; j < 52; j++) {
        if (i == j) d[i][j] = 0;
        else d[i][j] = INF;
      }
    }

    for (int i = 0; i < n; i++) {
      int u, v, dis;
      char a, b;
      cin >> a >> b >> dis;
      u = char2num(a);
      v = char2num(b);
      if (d[u][v] > dis) // why we seed first, some pastures are connected by more than one path
        d[u][v] = d[v][u] = dis;
    }

    // floyd warshall all pair shortest path
    for (int k = 0; k < 52; k++) 
      for (int i = 0; i < 52; i++) 
        for (int j = 0; j < 52; j++) 
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    pair<int, char> ans = {INF, '~'};
    for (int i = 26; i < 51; i++) 
      if (d[i][51] != INF && d[i][51] < ans.first) 
        ans = {d[i][51], i - 26 + 'A'};
    cout << ans.second << " " << ans.first << endl;
    
    return 0;
}
