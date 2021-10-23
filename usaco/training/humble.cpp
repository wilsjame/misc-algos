/*
ID: jgwilso1
PROG: humble
LANG: C++                 
*/
#include <iostream>
#include <cstdio>
#include <cassert>
using namespace std;

int main() {
  freopen("humble.in", "r", stdin);
  freopen("humble.out", "w", stdout);
  int numpr;
  cin >> numpr;
  int n;
  cin >> n;
  int pr[numpr];          // primes in given set S
  for (int i = 0; i < numpr; i++) {
    cin >> pr[i];
  }
  long h[100005] = {};    // humble numbers
  int pindex[numpr] = {}; // location of humble number to begin searching from for prime i
  h[0] = 1; // seed

  for (int hn = 1; hn <= n; hn++) {
    long prev_hn = h[hn - 1];
    long mn = 0x7FFFFFFF;
    for (int i = 0; i < numpr; i++) {
      // slide pindex to eliminate searching from beginning every loop iteration
      while (h[pindex[i]] * pr[i] <= prev_hn) {
        pindex[i]++;
      }
      if (h[pindex[i]] * pr[i] < mn) {
        mn = h[pindex[i]] * pr[i];
      }
      h[hn] = mn;
    }
    h[hn] = mn;
  }
  cout << h[n] << endl;

  return 0;
}


// bst set and min heap priority queue are fast enough
// but break memory limits on usaco grader...
/*
  int k;
  cin >> k;
  int n;
  cin >> n;
  long long a[k];
  vector<long long> h;
  set<long long> bst;
  for (int i = 0; i < k; i++) {
    cin >> a[i];
    bst.insert(a[i]);
  }
  for (int i = 0; i < k; i++) {
    for (int j = i + 1; j < k; j++) {
      bst.insert(a[i] * a[j]);
    }
  }
  for (int i = 0; i < n; i++) {
    h.push_back(*bst.begin());
    bst.erase(bst.begin());
    for (int j = 0; j < k; j++) {
        bst.insert(a[j] * h.back());
    }
  }
  for (auto x : h) {
    cerr << x << " ";
  } cerr << endl;
  cerr << h.back() << endl;
  cout << h.back() << endl;
*/
