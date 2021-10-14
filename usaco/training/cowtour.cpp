/*
ID: jgwilso1
PROG: cowtour
LANG: C++                 
*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int mxN = 155;
const double INF = 1e11;
double dia[mxN], color_dia[mxN]; 
bool visit[mxN];
vector<int> colors[mxN];
int g[mxN][mxN], color[mxN]; 
int n, c;

double dis(int a1, int b1, int a2, int b2) {
  int a = abs(a1 - a2);
  int b = abs(b1 - b2);
  a *= a;
  b *= b;
  return sqrt(a + b);
}

void dfs(int u) {
  if (visit[u]) 
    return; 
  visit[u] = true;
  color[u] = c;
  colors[c].push_back(u);
  for (int v = 1; v <= n; v++) 
    if (g[u][v]) 
      dfs(v);
}

int main() {
  freopen("cowtour.in", "r", stdin);
  freopen("cowtour.out", "w", stdout);
  cin >> n;
  vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= n; j++) 
      g[i][j] = s[j - 1] - '0';
  }
  // color componenets
  for (int i = 1; i <= n; i++) {
    if (visit[i]) continue;
    c += 1;
    dfs(i);
  }
  // floyd warshall 
  double dp[n + 1][n  + 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) { 
      if (i == j) dp[i][j] = 0;
      else if(g[i][j]) dp[i][j] = dis(a[i], b[i], a[j], b[j]);
      else dp[i][j] = INF;
    }
  }
  // node k is the intermediate node between i and j
  for (int k = 1; k <= n; k++) 
    for (int i = 1; i <= n; i++) 
      for (int j = 1; j <= n; j++) 
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
  // diameters from each node and for each component
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (dp[i][j] == INF) continue; // unreachable
      dia[i] = max(dia[i], dp[i][j]);
      color_dia[color[i]] = max(color_dia[color[i]], dp[i][j]);
    }
  }
  // enumerate connecting pairs of different colored nodes
  double ans = INF;
  for (int c1 = 1; c1 <= c; c1++) {
    for (int c2 = c1 + 1; c2 <= c; c2++) {
      for (auto i : colors[c1]) {
        for (auto j : colors[c2]) {
          // note: connected pastures does not guarantee a larger diamater
          double d1 = max(color_dia[color[i]], color_dia[color[j]]); // individual
          double d2 = dia[i] + dia[j] + dis(a[i], b[i], a[j], b[j]); // connected
          ans = min(ans, max(d1, d2));
        }
      }
    }
  }
  cout << fixed << setprecision(6) << ans << endl;
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

  return 0;
}
