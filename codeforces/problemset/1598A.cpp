#include <iostream>
#include <string>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s1, s2;
    cin >> n >> s1 >> s2;
    bool ok = true;
    for (int i = 0; i < n && ok; i++)
      if (s1[i] == '1' && s2[i] == '1') 
        ok = false;
    if (s2[n - 1] == '1') 
      ok = false;
    cout << (ok ? "YES" : "NO") << endl;
  }
  return 0;
}
