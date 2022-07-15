#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void debug_v(vector<int> v) {
  cout << "[";
  for (auto k : v) {
    cout << k << " ";
  }
  cout << "]" << endl;
}
void solve() {
  int N; cin >> N;
  vector<int> U(N);
  for (auto &i : U) cin >> i;
  vector<int> S(N);
  for (auto &i : S) cin >> i;

  // O(N) map students and skills
  vector<vector<long long>> bst(N);
  for (int i = 0; i < N; i++) 
    bst[U[i]-1].push_back(S[i]);

  // O(NlogN) sort skills
  for (int i = 0; i < N; i++) 
    sort(bst[i].rbegin(), bst[i].rend());

  // O(N) prefix sums
  for (int i = 0; i < N; i++) {
    vector<long long> psum; 
    for (int j = 0; j < int(bst[i].size()); j++) {
      if (j == 0)
        psum.push_back(bst[i][j]); 
      else
        psum.push_back(psum[j-1] + bst[i][j]);
    }
    bst[i] = psum; // conserve memory
  }

  // O(N) solve for K in O(1)
  vector<long long> ans(N);
  for (int i = 0; i < N; i++) {
    for (int k = 1; k <= int(bst[i].size()); k++) {
      ans[k-1] += bst[i][(bst[i].size() / k) * k - 1];
    }
  }

  for (auto const &i : ans)
    cout << i << " ";
  cout << endl;


  return;
}
int main() {
  int T; cin >> T;
  while (T--)
    solve();
  return 0;
}

// key is finding K in O(1) and memory management
// total students / group size = num groups
// num groups * group size = num of students
// minus 1 for indexing in prefix sum
