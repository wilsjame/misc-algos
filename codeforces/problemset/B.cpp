#include <iostream>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

#define ll long long
#define print(x) cerr << #x << " is " << x << endl;


void solve(char c, int l) {
    if (c == 'N' || c == 'S') {
        if 
    }
    else {
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    int N;
    cin >> N;

    //TODO build tree with N S E W starting nodes
    // where each node has two branches N,S -> E W ... E,W -> N S
    // bfs only count unique paths
    //
    // or generate unique combinations of length N?
    for (int i = 0; i < N; i++) {

    }
    if (N == 1 || N ==2) {
        cout << 4;
    }
    else {
        ll ans = 4;  
        for (int i = 0; i < N - 1; i++) {
            ans *= 2;
        }
        if (N % 2 == 0) {
            ;
        }
        else {
            cout << ans - (4 * (N -2));
        }

    }

    return 0;
}
