#include <iostream>
#include <string>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length();

    char mn = 'z' + 1;
    int mn_pos = -1;
    for (int i = 0; i < n; i++) {
      if (s[i] < mn) {
        mn = s[i];
        mn_pos = i;
      }
    }

    cout << s[mn_pos] << " ";
    for (int i = 0; i < n; i++) {
      if (i == mn_pos) continue;
      cout << s[i];
    }
    cout << endl;
  }

  return 0;
}
