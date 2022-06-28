#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int N, M;
  cin >> N >> M; 

  int sum = 0;
  for (int i = 0; i < N; i++) {
    int k;
    cin >> k;
    sum += k;
  }

  int ans = sum % M;
  cout << ans << endl;

  return;
}
int main() {
  //freopen("in.txt", "r", stdin);

  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    cout << "Case #" << i+1 << ": "; 
    solve();
  }

  return 0;
}
