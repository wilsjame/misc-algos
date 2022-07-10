#include <iostream>
using namespace std;
typedef long long ll;
void solve() {
  ll N, M, K;
  cin >> N >> M >> K;
  ll total = N-1 + N*(M-1);
  cout << (total == K ? "YES" : "NO") << endl;
}
int main() {
  ll T; cin >> T;
  while (T--)
    solve();
}
