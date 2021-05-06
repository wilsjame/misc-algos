#include <iostream>
using namespace std;
int m['z'+1];
int main() {
    int n; 
    cin >> n;
    char c;
    for (int i = 0; i <= n; i++) {
        cin.get(c);
        m[int(c)]++;
    }
    bool ans = true;
    for (int i = 0; i < 26; i++) {
        if (!m['a' + i] && !m['A' + i]) {
            ans = false;
            break;
        }
    }
    cout << (ans ? "YES" : "NO") << endl;
    return 0;
}
