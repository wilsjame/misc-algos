/*
ID: jgwilso1
PROG: ariprog
LANG: C++                 
*/
#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
int table[125000]; // bisquare lookup speed memory tradeoff

int main() {
    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    set<int> S; // bisquare set to ensure no duplicates
    vector<int> v;
    for (int p = 0; p <= m; p++) {
        for (int q = p; q <= m; q++) {
            S.insert((p * p) + (q * q));
            table[(p * p) + (q * q)]++;
        }
    }
    for (auto k : S) {
        v.push_back(k);
    }
    // brute-force *carefully* O((num of bisquares)^2)
    vector<pair<int, int>> ans;
    for (int i = 0; i < (int)v.size(); i++) {
        for (int j = i + 1; j < (int)v.size(); j++) {
            int d = v[j] - v[i];
            int cur = v[j] + d;
            int cnt = 2;
            while (cur <= (m * m) + (m * m) && cnt < n) {
                if (table[cur]) {
                    cur += d;
                    cnt++;
                }
                else {
                    break;
                }
            }
            if (cnt == n) {
                ans.push_back({d, v[i]});
            }
        }
    }
    if (ans.size()) {
        sort(ans.begin(), ans.end());
        for (auto k : ans) {
            cout << k.second << " " << k.first << endl;
        }
    }
    else {
        cout << "NONE" << endl;
    }
    return 0;
}

// bisquares p^2 + q^2, 0 <= p,q <= m
