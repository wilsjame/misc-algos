/*
ID: jgwilso1
PROG: lamps
LANG: C++                 
*/
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int mxN = 100;
int n, c, i;
vector<int> a(mxN+1, -1), button;
vector<vector<int>> ans;

// a and b are large (up to 100-bit) binary numbers
bool morethan(vector<int> a, vector<int> b) {
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) continue;
        if (a[i] > b[i]) return true;
        else return false;
    }
}

void dfs() {
    if ((int)button.size() == 4) {
        // clicks
        int cnt = 0;
        for (int i = 0; i < 4; i++)
            cnt += button[i] == 1;
        if (cnt > c) return;
        // turn lamps on and off
        vector<int> b(n, 1);
        if (button[0] == 1) {
            for (int i = 0; i < n; i++) 
                b[i] = 0;
        }
        if (button[1] == 1) {
            for (int i = 0; i < n; i += 2) 
                b[i] == 0 ? b[i] = 1 : b[i] = 0;
        }
        if (button[2] == 1) {
            for (int i = 1; i < n; i += 2) 
                b[i] == 0 ? b[i] = 1 : b[i] = 0;
        }
        if (button[3] == 1) {
            for (int i = 0; i < n; i += 3) 
                b[i] == 0 ? b[i] = 1 : b[i] = 0;
        }
        // validity
        for (int i = 0; i < n; i++) {
            if (a[i] == -1) continue;
            if (a[i] != b[i]) return;
        }
        // duplicates
        for (auto v : ans) 
            if (v == b) return;
        // ordered from least to largest as binary numbers
        if (ans.empty() || !morethan(ans.back(), b)) {
            ans.push_back(b);
        }
        else {
            for (int i = 0; i < (int)ans.size(); i++) {
                if (morethan(ans[i], b)) {
                    ans.insert(ans.begin()+i, b);
                    break;
                }
            }
        }

        return;
    }
    else {
        for (int i = 0; i <= 1; i++) {
            button.push_back(i);
            dfs();
            button.pop_back();
        }
    }
}

int main() {
    freopen("lamps.in", "r", stdin);
    freopen("lamps.out", "w", stdout);
    cin >> n >> c;
    cin >> i;
    while (i != -1) {
        a[i-1] = 1;
        cin >> i;
    }
    cin >> i;
    while (i != -1) {
        a[i-1] = 0;
        cin >> i;
    }
    dfs();
    if (ans.empty()) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        for (int i = 0; i < (int)ans.size(); i++) {
            for (auto x : ans[i]) 
                cout << x;
            cout << endl;
        }
    }

    return 0;
}
