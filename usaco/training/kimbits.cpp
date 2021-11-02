/*
ID: jgwilso1
PROG: kimbits
LANG: C++                 
*/
#include <iostream>
#include <cstdio>
using namespace std;

long long tri[32][32];

// binomial coefficients w/out overflow
void pascal_triangle() {
  tri[0][0] = 1; // 0 choose 0 
  for (int n = 1; n <= 31; n++) {
    for (int k = 0; k <= n; k++) {
      if (k == 0 || k == n) {
        tri[n][k] = 1;
      }
      else {
        tri[n][k] = tri[n - 1][k - 1] + tri[n - 1][k];
      }
    }
  }
}

int main() {
    freopen("kimbits.in", "r", stdin);
    freopen("kimbits.out", "w", stdout);
    long long N, L, I;
    cin >> N >> L >> I;

    pascal_triangle();
    string ans = "";
    for (int n = N; n > 0; --n) {
      // decide to set bit n by looking at
      // the number of combinations for length n-1
      // using L remaining bits
      long long sizeofset = 0;
      for (int k = 0; k <= L; k++) {
        sizeofset += tri[n - 1][k];
      }
      // set this bit if index is greater than
      // the number of combinations for n-1 
      if (I > sizeofset) {
        ans += '1';
        L--;            // set bit no longer available
        I -= sizeofset; // index adjusts with set bits
      }
      else {
        ans += '0';
      }
    }
    cout << ans << endl;

    return 0;
}

/*
// n choose k combinations (overflow X_X)
long long nCk(long long n, long long k) {
  int ki = k;
  long long num = 1;
  for (long long i = n; i > n - k; --i) {
    if (i == ki) {
      ki--;
    }
    else {
      num *= i;
    }
  }
  long long den = 1;
  for (long long i = 1; i <= ki; i++) {
    den *= i;
  }
  return num / den; 
}
*/
