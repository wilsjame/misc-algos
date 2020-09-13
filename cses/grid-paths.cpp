#include <iostream>
#include <vector>
using namespace std;
int main() {
    //freopen("input.txt", "r", stdin);
    int n, m = 1e9+7;
    cin >> n;
    vector< vector<char> > g(n + 1, vector<char>(n + 1));
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= n; x++) {
            cin >> g[y][x];
        }
    }

    // paths[y][x] is the number of paths beginning at the
    // upper-left square and ending at the square (y,x)
    vector< vector<int> > paths(n + 1, vector<int>(n + 1, 0));
    // one path to starting position
    if (g[1][1] == '.')
        paths[1][1] = 1;
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= n; x++) {
            if (g[y][x] == '.') {
                // square is reachable from the left and from above
                paths[y][x] += (paths[y][x - 1] + paths[y -1][x]);
                paths[y][x] %= m;
            }
        }
    }
    cout << paths[n][n];

    return 0;
}
