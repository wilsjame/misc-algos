/*
ID: jgwilso1
PROG: concom
LANG: C++                 
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int mxN = 100;
int g[mxN + 1][mxN + 1];
int owns[mxN + 1][mxN + 1];
int visit[mxN + 1][mxN + 1];

void dfs(int a, int i, int j) {
  if (visit[i][j]) return;
  visit[i][j] = true;

  for (; j <= mxN; j++) {  
    owns[a][j] += g[i][j]; // a controls i so include all i ownerships of j 
    if (owns[a][j] > 50) { // a controls j
      dfs(a, j, 1); // start new dfs on company j
    }
  }
}

int main() {
    freopen("concom.in", "r", stdin);
    freopen("concom.out", "w", stdout);
    int n, a, b, c;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a >> b >> c;
      g[a][b] = c;
    }

    for (a = 1; a <= mxN; a++) { 
      memset(visit, 0, sizeof(visit));
      dfs(a, a, 1);

      for (b = 1; b <= mxN; b++) {
        if (owns[a][b] > 50 && a != b) {
          cout << a << " " << b << endl;
        }
      }
    }

    return 0;
}
