#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int n, k, cnt = 0;
        string s;
        cin >> n >> k >> s;
        for (int i = 0; i < n /2; i++) {
            if (s[i] != s[n - i - 1]) {
                cnt++;
            }
        }
        cout << "Case #" << tc << ": " << abs(k - cnt) << endl;
    }
    return 0;
}
