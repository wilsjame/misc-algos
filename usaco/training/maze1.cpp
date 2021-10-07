/*
ID: jgwilso1
PROG: maze1
LANG: C++                 
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <cstring>
using namespace std;

const int INF = 1e5;
const int mxW = 2*38+1, mxH = 2*100+1;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int g[mxW + 5][mxH + 5]; // nodes numbered, walls -1
int adj[mxW + 5][mxH + 5]; // adj matrix 
int dist[mxW * mxH][mxW * mxH]; // is best distance from node i to node j

int main() {
  freopen("maze1.in", "r", stdin);
  freopen("maze1.out", "w", stdout);

  string s;
  vector<int> exit;
  int w, h, n = 0;
  cin >> w >> h;
  cin >> s; // flush
  w = 2 * w + 1;
  h = 2 * h + 1;
  for (int i = 1; i <= h; i++) {
    getline(cin, s);
    for (int j = 1; j <= w; j++) {
      s[j - 1] == ' ' ? g[i][j] = ++n : g[i][j] = -1;
      if (g[i][j] != -1 && ((i == 1 || i == h) || (j == 1 || j == w)))
        exit.push_back(n);
    }
  }

  /*
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cerr << g[i][j] << " ";
    }
    cerr << endl;
  }
  assert(exit.size() == 2);
  cerr << "exit" << endl; 
  for (auto k : exit) cerr << k << endl;
  cerr << "nodes " << n << endl;
  */

  // each node do shortest path to both exits, ans is max of those costs
  // Floyd-Warshall shortest paths between all pairs of nodes 
  // requires adj matrix... TLE and memory limit X_X works though!
  // time O(n^3), space O(n^2), max n = 15200 nodes
  
  // start with single edge paths
  for (int i = 1; i <= n; i++) 
    for (int j = 1; j <= n; j++) 
      i == j ? dist[i][j] = 0 : dist[i][j] = INF;

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {

      if (g[i][j] != -1)  {
        for (int k = 0; k < 4; k++)  {
          if (g[i + dx[k]][j + dy[k]] != -1) {
            int n1 = g[i][j];
            int n2 = g[i + dx[k]][j + dy[k]];
            dist[n1][n2] = 1;
            dist[n2][n1] = 1;
          }
        }
      }
      
    }
  }

  /*
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cerr << dist[i][j] << " ";
    }
    cerr << endl;
  }
  cerr << endl;
  */

  // build dp table
  for (int k = 1; k <= n; k++) // k is the intermediate node
    for (int i = 1; i <= n; i++) 
      for (int j = 1; j <= n; j++) 
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

  /*
  cerr << endl;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cerr << dist[i][j] << " ";
    }
    cerr << endl;
  }
  */

  int ans = 0;
  for (int k = 1; k <= n; k++) {
    //cerr << k << " node is dist from nearest exit " << min(dist[k][exit[0]], dist[k][exit[1]]) << endl;
    ans = max(ans, min(dist[k][exit[0]], dist[k][exit[1]]));
  }

  cerr << "ans " << ans << endl;
  cerr << "ans / 2 " << (ans + 1) / 2 << endl;
  cout << (ans + 1) / 2 << endl;

  return 0;
}

