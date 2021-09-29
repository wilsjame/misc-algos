#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), asort;
    for (auto &x : a) 
      cin >> x;
    asort = a;
    sort(asort.begin(), asort.end());

    // greedy, we have n moves to use (also bubble sort?)
    deque<vector<int>> shifts;
    int k = 0;
    for (int i = 0; i < n; i++) {
      if (a == asort) break; 
      else if (a[i] == asort[i]) continue;

      int des = i;
      int pos = find(a.begin() + i, a.end(), asort[i]) - a.begin();
      int dis = pos - des;
      for (int j = pos; j > des; j--) 
        swap(a[j], a[j - 1]);
      k++;

      shifts.push_front({des + 1, pos + 1, dis});
    }

    cout << k << endl;
    if (k == 0) {
      cout << endl;
    }
    else {
      while (!shifts.empty()) {
        for (auto x : shifts.back()) {
          cout << x << " ";
        }
        cout << endl;
        shifts.pop_back();
      }
    }
  }

  return 0;
}
