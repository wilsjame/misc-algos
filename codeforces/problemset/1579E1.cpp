#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int main () {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    deque<int> a, b;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a.push_back(x);
    }
    while (!a.empty()) {
      int af = a.front();
      a.pop_front();
      if (b.empty()) {
        b.push_back(af);
      }
      else {
        int bf = b.front();
        if (af < bf)
          b.push_front(af);
        else
          b.push_back(af);
      }
    }
    for (auto k : b)
      cout << k << " ";
    cout << endl;
  }

  return 0;
}
