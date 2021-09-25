/*
ID: jgwilso1
PROG: prefix
LANG: C++                 
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

const int mxN = 200000;
string S;
vector<string> prim;
int reachable[mxN + 1];

int main() {
  freopen("prefix.in", "r", stdin);
  freopen("prefix.out", "w", stdout);

  string line;
  for (getline(cin, line); line != "."; getline(cin, line)) {
    istringstream ss(line);
    string p;
    while (ss >> p)
      prim.push_back(p);
  }
  while (getline(cin, line)) 
    S += line;
  int N = S.length();

  // lv  : pos in S
  // lv2 : primitive
  // lv3 : pos in primitive
  int best = 0;
  reachable[0] = 1;
  // mark all prefix matches from this letter
  for (int lv = 0; lv < N; lv++) {
    if (reachable[lv]) {
      // try every primitive
      for (int lv2 = 0; lv2 < (int)prim.size(); lv2++) {
        int primn = prim[lv2].size();
        int lv3 = 0;
        for (; lv + lv3 < N && lv3 < primn && S[lv + lv3] == prim[lv2][lv3]; lv3++) {}
        // this primitive matches!
        if (lv3 == (int)prim[lv2].size()) {
          reachable[lv + lv3] = 1;
          best = max(best, lv + lv3);
        }
      }
    }
  }
  cout << best << endl;

  return 0;
}
