/*
ID: jgwilso1
PROG: holstein
LANG: C++                 
*/
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int mxV = 25, mxG = 15, mxN = 1000;
int V, G;
vector<int> v(mxV), g[mxG+1];

int cnt = mxG+1;
vector<int> permutation, totalv, feedn;

// complete search worst case 2^mxG
void search() { 
    if ((int)permutation.size() == G) {
        int curcnt = 0;
        vector<int> curv (V, 0), curfeedn;
        for (int i = 0; i < G; i++) {
            if (permutation[i]) {
                for (int j = 0; j < V; j++) {
                    curv[j] += g[i][j];
                }
                curfeedn.push_back(i+1);
                curcnt++;
            }
        }
        for (int i = 0; i < V; i++) {
            if (curv[i] < v[i]) {
                return;
            }
        }
        if (curcnt <= cnt) {
            cnt = curcnt;
            totalv = curv;
            feedn = curfeedn;
        }
        return;
    }
    else {
        for (int i = 0; i <= 1; i++) {
            permutation.push_back(i);
            search();
            permutation.pop_back();
        }
    }
}

int main() {
    freopen("holstein.in", "r", stdin);
    freopen("holstein.out", "w", stdout);
    cin >> V;
    for (int i = 0; i < V; i++) {
        cin >> v[i];
    }
    cin >> G;
    for (int i = 0; i < G; i++) {
        int x;
        for (int j = 0; j < V; j++) {
            cin >> x;
            g[i].push_back(x);
        }
    }
    search();
    cout << cnt << " ";
    for (int i = 0; i < (int)feedn.size(); i++) {
        cout << feedn[i];
        cout << (i < (int)feedn.size()-1 ? ' ' : '\n'); // usaco would like no space before newline
    }

    return 0;
}
