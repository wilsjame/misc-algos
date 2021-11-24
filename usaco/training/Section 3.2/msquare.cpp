/*
ID: jgwilso1
PROG: msquare
LANG: C++                 
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

map<int, string> path;
set<int> visit;

int permToInt(vector<int> u) {
  int res = 0;
  for (int i = 0; i < 8; i++) {
    int exp = 1;
    for (int j = 0; j < 7 - i; j++)
      exp *= 10;
    res += u[i] * exp;
  }
  return res;
}

vector<int> applyA(vector<int> perm) {
  vector<int> res(8);
  for (int i = 0; i < 8; i++) {
    res[i] = perm[7 - i];
  }
  return res;
}

vector<int> applyB(vector<int> perm) {
  vector<int> res(8);
  for (int i = 0; i < 4; i++) {
    res[i] = perm[(i + 3) % 4];
    res[(i + 4) % 4 + 4] = perm[(i + 5) % 4 + 4];
  }
  return res;
}

vector<int> applyC(vector<int> perm) {
  vector<int> res(8);
  int m[8] = {0, 6, 1, 3, 4, 2, 5, 7};
  for (int i = 0; i < 8; i++) {
    res[i] = perm[m[i]];
  }
  return res;
}

void bfs(vector<int> start, vector<int> finish) {
  queue<vector<int>> q;
  q.push(start);
  while(!q.empty()) {
    vector<int> u = q.front();
    q.pop();
    if (u == finish) {
      return;
    }
    vector<int> A = applyA(u);
    vector<int> B = applyB(u);
    vector<int> C = applyC(u);
    int source = permToInt(u);
    int a = permToInt(A);
    int b = permToInt(B);
    int c = permToInt(C);
    if (!visit.count(a)) {
      visit.insert(a);
      path[a] = path[source] + 'A'; 
      q.push(A);
    }
    if (!visit.count(b)) {
      visit.insert(b);
      path[b] = path[source] + 'B';
      q.push(B);
    }
    if (!visit.count(c)) {
      visit.insert(c);
      path[c] = path[source] + 'C';
      q.push(C);
    }
  }
}

int main() {
  freopen("msquare.in", "r", stdin);
  freopen("msquare.out", "w", stdout);
  vector<int> start(8); 
  vector<int> finish(8);
  for (int i = 0; i < 8; i++) {
    start[i] = i + 1;
    cin >> finish[i];
  }
  path[permToInt(start)] = "";
  bfs(start, finish);
  string ans = path[permToInt(finish)];
  int N = ans.size();
  cout << N << endl;
  for (int i = 0; i < N; i += 60) {
    cout << ans.substr(i, i + 60);
    if (i + 60 < N) {
      cout << endl;
    }
  }
  cout << endl;

  return 0;
}

/*
 * 8! board configurations
 * each config is a node
 * each transformation is an edge: A B C
 * BFS from start to finish to get shortest path
 * keep track of path taken
 * TODO: replace vectors and integers with strings, cleaner
 */
