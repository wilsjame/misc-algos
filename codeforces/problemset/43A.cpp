#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
    map<string, int> m;
    string s, ans;
    int n, count = 0;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> s;
        m[s]++;
        if (m[s] > count) {
            count = m[s];
            ans = s;
        }
    }
    cout << ans << endl;

    return 0;
}
