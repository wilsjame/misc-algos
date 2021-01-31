#include <iostream>
#include <string>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s, res;
        int n;
        cin >> n >> s;
        int idx = 0;
        for (int i = 0, j = n; i < j && j <= 2 * n - 1; i++, j++) {
            /*
            cerr << i << " " << j << endl;
            for (int k = i; k < j; k++) {
                cerr << s[k];
            }
            cerr << endl;
            */
            res += s[i + idx++];
            //cerr << "res " << res << endl;
        }
        cout << res << endl;

    }
    return 0;
}
