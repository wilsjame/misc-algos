#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  else {
    return gcd(b, a % b);
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    // find gcd of set bits in each position
    int gcd_ = -1;
    for (int bit = 29; bit >= 0; --bit) {
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        if (a[i]&(1<<bit)) {
          cnt += 1;
        }
      }
      if (gcd_ == -1) {
        gcd_ = cnt;
      }
      else {
        gcd_ = gcd(gcd_, cnt); // O(log(min(a, b)))
      }
    }
    for (int k = 1; k <= n; k++) {
      if (gcd_ % k == 0) { 
        cout << k << " ";
      }
    }
    cerr << endl;
  }

  return 0;
}
