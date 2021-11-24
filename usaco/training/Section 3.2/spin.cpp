/*
ID: jgwilso1
PROG: spin
LANG: C++                 
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

int main() {
    freopen("spin.in", "r", stdin);
    freopen("spin.out", "w", stdout);
    int v[5] = {0};              // wheel speeds
    vector<pair<int, int>> w[5]; // wheel wedges
    for (int i = 0; i < 5; i++) {
      cin >> v[i];
      int n;
      cin >> n;
      for (int j = 0; j < n; j++) {
        int a;
        cin >> a;
        int b;
        cin >> b;
        w[i].push_back({a, b});
      }
    }
    // simulate, wedges will never align if alignment doesn't occur in one rotation (360 deg) 
    for (int t = 0; t < 360; t++) {
      int visit[360] = {0};
      // update openings for each wheel
      for (int i = 0; i < 5; i++) {
        for (auto wedge : w[i]) {
          int a = wedge.first;
          int b = wedge.second;
          b += a;
          b %= 360;
          if (a <= b) { // ex) 0->1
            for (int j = a; j <= b; j++) visit[j]++; 
          }
          else { // ex) 359->0
            for (int j = a; j < 360; j++) visit[j]++;
            for (int j = 0; j <= b ; j++) visit[j]++;
          }
        }
      }
      // check if all wheel openings align
      for (int a = 0; a < 360; a++) {
        if (visit[a] == 5) {
          cout << t << endl;
          return 0;
        }
      }
      // move each wheel's start angle for the next iteration
      for (int i = 0; i < 5; i++) {
        for (auto &wedge : w[i]) {
          int a = wedge.first;
          a = (a + v[i]) % 360; 
          wedge.first = a;
        }
      }
    }
    cout << "none" << endl;

    return 0;
}
