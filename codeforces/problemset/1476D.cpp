#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        // dp going left
        vector<int> dp_l(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            if (i > 1 && (s[i - 1] == 'L' && s[i - 2] == 'R')) {
                dp_l[i] += dp_l[i - 2] + 1;
            }
            else if (s[i - 1] == 'L') {
                dp_l[i]++;
            }
        }
        // dp going right
        vector<int> dp_r(n + 1, 1);
        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1 && (s[i] == 'R' && s[i + 1] == 'L')) {
                dp_r[i] += dp_r[i + 2] + 1;
            }
            else if (s[i] == 'R') {
                dp_r[i]++;
            }
        }

        for (int i = 0; i <= n; i++) {
            cout << dp_l[i] + dp_r[i] - 1 << " ";
        }
        cerr << endl;
    }

    return 0;
}
