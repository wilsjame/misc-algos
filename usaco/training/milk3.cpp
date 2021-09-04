/*
ID: jgwilso1
PROG: milk3
LANG: C++                 
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int mxN = 20;
bool vis[mxN + 1][mxN + 1][mxN + 1];
int A, B, C;
vector<int> ans;

void dfs(int a, int b, int c) {
    if (vis[a][b][c])  {
        return;
    }
    else {
        vis[a][b][c] = true;
    }
    // process node
    if (a == 0) {
        ans.push_back(c);
    }
    // 6 pours (edges)
    if (c > 0) {
        // c->a, c->b
        if (a < A) dfs(min(A, a + c), b, max(0, c - (A - a)));
        if (b < B) dfs(a, min(B, b + c), max(0, c - (B - b)));
    }
    if (b > 0) {
        // b->a, b->c
        if (a < A) dfs(min(A, a + b), max(0, b - (A - a)), c);
        if (c < C) dfs(a, max(0, b - (C - c)), min(C, c + b));
    }
    if (a > 0) {
        // a->b, a->c
        if (b < B) dfs(max(0, a - (B - b)), min(B, b + a), c);
        if (c < C) dfs(max(0, a - (C - c)), b, min(C, c + a));
    }
}

int main() {
    freopen("milk3.in", "r", stdin);
    freopen("milk3.out", "w", stdout);
    cin >> A >> B >> C;
    dfs(0, 0, C);
    sort(ans.begin(), ans.end());
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] << (i + 1 < (int)ans.size() ? ' ' : '\n');
    }
    return 0;
}
