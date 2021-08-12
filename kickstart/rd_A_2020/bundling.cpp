#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
const int mxN = 2e6, as = 26;
int ans, sz = 1, trie[mxN + 1][as], cnt[mxN + 1][as];

// c is current node
// empty string is node 0 and counts toward sz ex) FIRE sz=5
// trie[c][letter] is the node from c to letter
inline void ins(string s) {
    int c = 0; 
    for (int i = 0; i < (int)s.size(); i++) {
        cnt[c][s[i] - 'A']++;
        if (!trie[c][s[i] - 'A']) {
            trie[c][s[i] - 'A'] = sz;
            c = sz++;
        }
        else {
            c = trie[c][s[i] - 'A'];
        }
    }
}

void dfs(int u, int k) {
    for (int i = 0; i < 26; i++) {
        ans += cnt[u][i] / k;
        if (trie[u][i]) {
            dfs(trie[u][i], k);
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int n, k;
        cin >> n >> k;
        ans = 0, sz = 0;
        memset(trie, 0, sizeof(trie));
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            ins(s);
        }
        dfs(0, k);
        printf("Case #%d: %d\n", tt, ans);
    }
    return 0;
}
