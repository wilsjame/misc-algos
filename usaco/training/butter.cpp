/*
ID: jgwilso1
PROG: butter
LANG: C++                 
*/
#include <iostream>
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

const int INF = 1e9;
int cow[501];
vector<pair<int, int>> adj[801];

int main() {
  freopen("butter.in", "r", stdin);
  freopen("butter.out", "w", stdout);
  int N, P, C; // cows, pastures, connecting paths
  cin >> N >> P >> C;
  for (int i = 1; i <= N; i++) {
    cin >> cow[i];
  }
  for (int i = 1; i <= C; i++) {
    int a, b, d;
    cin >> a >> b >> d;
    adj[a].push_back({b, d});
    adj[b].push_back({a, d});
  }
  // dijkstra greedy shortest path each pasture
  int res = INF;
  priority_queue<pair<int, int>> mn_heap; // contains {cur dist to, node}, easily access min dist node
  for (int source = 1; source <= P; source++) {
    int dist[P + 1];
    bool processed[P + 1];
    for (int i = 1; i <= P; i++) {
      dist[i] = INF;
      processed[i] = false;
    }
    dist[source] = 0;
    mn_heap.push({0, source});
    while (!mn_heap.empty()) {
      int cur = mn_heap.top().second;
      mn_heap.pop();
      if (processed[cur]) 
        continue;
      processed[cur] = true;
      for (auto neighbor : adj[cur]) {
        int n = neighbor.first;
        int w = neighbor.second;
        if (dist[cur] + w < dist[n]) {
          dist[n] = dist[cur] + w;
          mn_heap.push({-dist[n], n}); // negative hack min elements
        }
      }
    }
    int c = 0;
    for (int i = 1; i <= N; i++) {
      c += dist[cow[i]];
    }
    res = min(res, c);
  }
  cout << res << endl;

  return 0;
}
