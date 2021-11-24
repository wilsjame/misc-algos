/*
ID: jgwilso1
PROG: maze1
LANG: C++                 
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
using namespace std;

const int mxH = 100*2+1, mxW = 38*2+1; 
const int INF = mxH * mxW; 
int w, h, dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}, dist[mxH][mxW];
char g[mxH][mxW];
vector<pair<int, int>> exits; 

struct Node {
  int x, y, d;
};

queue<Node> q;
bool visit[mxH][mxW];

void bfs() {
  while (!q.empty()) {
    Node u = q.front();
    q.pop();
    int x = u.x, y = u.y;

    for (int k = 0; k < 4; k++) {
      int x2 = x + dx[k], y2 = y + dy[k];
      if (x2 > 0 && y2 > 0 && x2 < h - 1 && y2 < w - 1 && !visit[x2][y2] && g[x2][y2] == ' ') {
        visit[x2][y2] = true;
        dist[x2][y2] = min(dist[x2][y2], u.d + 1); 
        q.push((Node){x2, y2, u.d + 1});
      }
    }

  }
  return;
}

int main() {
  freopen("maze1.in", "r", stdin);
  freopen("maze1.out", "w", stdout);
  string s;
  cin >> w >> h;
  w = 2 * w + 1;
  h = 2 * h + 1;
  getline(cin, s); // flush extra input char
  for (int i = 0; i < h; i++) {
    getline(cin, s);
    for (int j = 0; j < w; j++) {
      g[i][j] = s[j];
      if ((i == 0 ||  i == h - 1 || j == 0 || j == w - 1) && g[i][j] == ' ') 
        exits.push_back({i, j});
    }
  }

  for (int i = 0; i < h; i++) 
    for (int j = 0; j < w; j++) 
      dist[i][j] = INF;

  for (auto pr : exits) { 
    memset(visit, 0, sizeof(visit));
    q.push((Node){pr.first, pr.second, 1});
    bfs();
  }

  int ans = 0;
  for (int i = 0; i < h; i++) 
    for (int j = 0; j < w; j++) 
        if (dist[i][j] != INF) 
          ans = max(ans, dist[i][j]);
  cout << ans / 2 << endl;

  return 0;
}
