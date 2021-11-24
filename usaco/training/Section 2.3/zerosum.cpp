/*
ID: jgwilso1
PROG: zerosum
LANG: C++                 
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
char op[3] = {'+', '-', ' '};
string s;
vector<string> sol;

void dfs(int d) {
  if (d == n) {
    // process op sequence
    string opseq;
    vector<int> nums = {1};
    for (int i = 2; i <= n; i++) {
      if (s[i - 2] == ' ') {
        int x = nums.back();
        nums.pop_back();
        nums.push_back(x * 10 + i);
      }
      else {
        nums.push_back(i);
        opseq.push_back(s[i - 2]);
      }
    }
    int sum = nums[0];
    for (int i = 0; i < (int)opseq.length(); i++) {
      if (opseq[i] == '+')
        sum += nums[i + 1];
      else 
        sum -= nums[i + 1];
    }
    if (sum == 0) 
      sol.push_back(s);

    return;
  }
  else {
    for (int i = 0; i < 3; i++) {
      s += op[i];
      dfs(d + 1);
      s.pop_back();
    }
  }
}

int main() {
    freopen("zerosum.in", "r", stdin);
    freopen("zerosum.out", "w", stdout);
    cin >> n;

    dfs(1);
    sort(sol.begin(), sol.end());
    for (auto k : sol) {
      for (int i = 1; i <= n; i++) {
        cout << i;
        if (i < n) cout << k[i - 1];
      }
      cout << endl;
    }

    return 0;
}
