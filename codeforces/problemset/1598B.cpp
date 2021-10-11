#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> a(n , vector<int>(5));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        cin >> a[i][j];
      }
    }
    bool ok = false;
    for (int d1 = 0; d1 < 5; d1++) {
      for (int d2 = d1 + 1; d2 < 5; d2++) {
        int sz1 = 0;
        int sz2 = 0;
        int sz12 = 0;
        for (int i = 0; i < n; i++) {
          sz12 += a[i][d1] && a[i][d2];
          sz1 += a[i][d1];
          sz2 += a[i][d2];
        }
        if (sz1 >= n / 2 && sz2 >= n / 2) 
          if ((sz1 + sz2) - n == sz12) 
            ok = true;
      }
    }
    if (ok)
      cout << "YES" << endl;
    else 
      cout << "NO" << endl;
  }
  return 0;
}
