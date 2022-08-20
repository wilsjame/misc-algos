#include <iostream>
#include <algorithm>
using namespace std;

void solve() {
  int N; 
  cin >> N;

  int mxN=0, mxE=0, mxS=0, mxW=0;

  for(int i=0;i<N;i++) {
    int x, y;
    cin >> x >> y;
    if (x < 0)
      mxW = max(mxW, abs(x));
    else if (x > 0)
      mxE = max(mxE, abs(x));
    else if (y < 0)
      mxS = max(mxS, abs(y));
    else if (y > 0)
      mxN = max(mxN, abs(y));
  }
  // Manhatta distance is optimal.
  int ans = 2*(mxN+mxE+mxS+mxW);

  cout << ans << endl;
}

int main() {
  int T; cin >> T;
  while(T--)
    solve();
  return 0;
}
