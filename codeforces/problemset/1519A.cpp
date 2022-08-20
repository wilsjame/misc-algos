#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

void solve() {
  ll a, b, d;
  cin >> a >> b >> d;

  ll dtotal = min(a, b) * d;
  ll leftover = abs(a - b);
  cout << (leftover <= dtotal ? "YES" : "NO") << endl;
}

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    solve();
  }
}
