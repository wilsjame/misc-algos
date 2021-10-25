#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
      cin >> x;
    }
    int q;
    cin >> q;
    vector<pair<int, int>> qs;
    int mx_step = -1;
    for (int i = 0; i < q; i++) {
      int x; // ax
      cin >> x;
      int k; // step
      cin >> k;
      mx_step = max(mx_step, k);
      qs.push_back({x, k});
    }

    // brute force generate mx_step or until steady states of a
    vector<vector<int>> A;
    A.push_back(a); // 0th step
    vector<int> a_prev = a;
    vector<int> cnt_prev(n + 1, 0);
    for (int i = 0; i < n; i++) {
      cnt_prev[a[i]]++;
    }

    int steady_step = 1e9+5;
    for (int i = 1; i <= mx_step; i++) {
      vector<int> a_cur;
      vector<int> cnt_cur(n + 1, 0);
      for (int j = 0; j < n; j++) {
        a_cur.push_back(cnt_prev[a_prev[j]]);
        cnt_cur[a_cur[j]]++;
      }
      A.push_back(a_cur);
      if (a_prev == a_cur) {
        steady_step = i;
        break;
      }
      else {
        a_prev = a_cur; 
        cnt_prev = cnt_cur;
      }
    }

    for (int i = 0; i < q; i++) {
      int x;
      x = qs[i].first;
      int k;
      k = min(steady_step, qs[i].second);
      cout << A[k][x - 1] << endl;
    }
  }

  return 0;
}
