#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
string solve() {
    string s;
    cin >> s;
    int n = s.size();
    int cnt[26] = {};
    for (char d : s)
        cnt[d-'a']++;
    for (int i = 0; i < 26; i++) 
        if (2 * cnt[i] > n) 
            return "IMPOSSIBLE";
    // -> aabbc sort
    // -> bbcaa 1/2 shift
    // map a->b, a->b, b->c, b->a, c->a
    vector<pair<char, int>> v;
    for (int i = 0; i < n; i++) {
        v.push_back({s[i], i});
    }
    sort(v.begin(), v.end());
    string a(n, 'x');
    for (int i = 0; i < n; i++) {
        a[v[i].second] = v[(i + n / 2) % n].first;
    }
    return a;
}
int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        string ans = solve();
        cout << "Case #" << tc << ": " << ans << endl;
    }
    return 0;
}
