#include <iostream>
using namespace std;

bool solve() {
  // Best case is equal to the mx value.
  // So if 5 is the highest number the optimal
  // operations to reduce must be five.
  // Check if given permutation is optimal.
  /*
   *       <=mx      <=mx
   *  |<---------mx--------->|
   *
   */
  
  int N;
  cin >> N;

  int mx = -1;
  int mxIdx = -1;
  int A[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    if (A[i] > mx) {
      mx = A[i];
      mxIdx = i;
    }
  }

  // Scan left.
  bool ok = true;
  int lp = mxIdx - 1;
  while (lp >= 0) {
    if (A[lp] > A[lp+1]) {
      ok = false;
      break;
    }
    lp--;
  }

  // Scan right.
  int rp = mxIdx + 1;
  while (rp < N) {
    if (A[rp] > A[rp-1]) {
      ok  = false;
      break;
    }
    rp++;
  }

  return ok;
}

int main() {
  int T; cin >> T;
  while(T--) {
    cout << (solve() ? "YES" : "NO") << endl;
  }
  return 0;
}
