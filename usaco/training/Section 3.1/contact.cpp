/*
ID: jgwilso1
PROG: contact
LANG: C++                 
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

string s; // input data

// compare strings representing binary numbers
bool compf(string s1, string s2) {
  int n1 = s1.length() - 1;
  int n2 = s2.length() - 1;
  if (n1 < n2) {
    return true;
  }
  else if (n2 > n1) {
    return false;
  }
  else {
    for (int i = 0;; i++) {
      if (s1[i] == '1' && s2[i] == '0') {
        return false;
      }
      else if (s1[i] == '0' && s2[i] == '1') {
        return true;
      }
    }
  }
}

int main() {
    freopen("contact.in", "r", stdin);
    freopen("contact.out", "w", stdout);
    int a;
    cin >> a;
    int b; 
    cin >> b;
    int n;
    cin >> n;
    string line;
    while (getline(cin, line)) {
      s += line;
    }
    map<string, int> m;
    int N = s.length();
    for (int i = 0; i < N; i++) {
      for (int j = a; j <= b; j++) {
        if (i + j <= N) {
          string sub = s.substr(i, j);
          m[sub]++;
        }
      }
    }
    map<int, vector<string>, greater<int>> m2;
    for (auto k : m) {
      m2[k.second].push_back(k.first);
    }
    int cnt = 0;
    for (auto k : m2) {
      cout << k.first << endl;
      sort(k.second.begin(), k.second.end(), compf);
      int sz = k.second.size();
      for (int i = 0; i < sz; i++) { 
        cout << k.second[i];
        // output formatting ;_;
        if ((i + 1) % 6 == 0 && i < sz - 1) {
          cout << endl;
        }
        else if (i < sz - 1) {
          cout << " ";
        }
      }
      cout << endl;
      if (++cnt == n) {
        break;
      }
    }

    return 0;
}

// one pass. at each index search ahead [a, b] subsequence length and
// store frequency in table1. after filling table1, swap dimensions
// into table2 and then use the comparator to sort the binary numbers
// represented as strings
