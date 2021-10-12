#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<int> ca(n + 1), cb(n + 1);
    for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
      ca[a[i]]++;
      cb[b[i]]++;
    }
    long long good = (long long) n * (n - 1) * (n - 2) / 6;
    long long bad = 0;
    for (int i = 0; i < n; i++) 
      bad += (long long) (ca[a[i]] - 1) * (cb[b[i]] - 1);
    cout << good - bad << endl;
  }

  return 0;
}
