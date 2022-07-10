#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
int main() {
  ll N; cin >> N;
  vector<pair<ll, ll>> A(N);
  for (ll i = 0; i < N; i++) {
    ll c; cin >> c;
    A[i] = make_pair(c, i);
  }
  sort(A.rbegin(), A.rend());

  ll cnt = 1;
  for (ll i = 1; i < N; i++) {
    cnt += A[i].first*i+1;
  }

  cout << cnt << endl;
  for (auto pr : A)
    cout << pr.second+1 << " ";
  cout << endl;
}
