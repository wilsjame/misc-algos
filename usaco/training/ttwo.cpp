/*
ID: jgwilso1
PROG: ttwo
LANG: C++                 
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <utility>
using namespace std;

struct Cell {
  char id;
  pair<int, int> pos;
  int d = 0;
};

char g[10][10], D[4] = {'N', 'E', 'S', 'W'};
int cnt;

void automata(Cell &a) {
  int i, j;
  i = a.pos.first;
  j = a.pos.second;
  switch (D[a.d]) {
    case 'N': i--; break;
    case 'E': j++; break;
    case 'S': i++; break;
    case 'W': j--; break;
  }
  if (g[i][j] == '*' || i < 0 || i > 9 || j < 0 || j > 9) {
    a.d = (a.d + 1) % 4;
  }
  else {
    g[a.pos.first][a.pos.second] = '.';
    g[i][j] = a.id; 
    a.pos.first = i;
    a.pos.second = j;
  }
}

int main() {
  freopen("ttwo.in", "r", stdin);
  freopen("ttwo.out", "w", stdout);

  Cell f, c;
  f.id = 'F';
  c.id = 'C';

  for (int i = 0; i < 10; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < 10; j++) {
      g[i][j] = s[j];
      if (g[i][j] == 'F') f.pos = {i, j};
      if (g[i][j] == 'C') c.pos = {i, j};
    }
  }

  for (; f.pos != c.pos && cnt < 160000; cnt++) { // 100*4*2 states 
    automata(f);
    automata(c);
  }
  cout << (f.pos == c.pos ? cnt : 0) << endl;

  return 0;
}
