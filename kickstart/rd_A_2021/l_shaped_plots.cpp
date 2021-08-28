#include <iostream>
#include <utility>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int r, c;
        cin >> r >> c;
        int g[r][c] = {};
        int n[r][c] = {};
        int e[r][c] = {};
        int s[r][c] = {};
        int w[r][c] = {};
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> g[i][j];
            }
        }
        // dp stores
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (g[i][j] && i > 0 && g[i - 1][j]) {
                    n[i][j] += n[i - 1][j] + 1;
                }
            }
        }
        for (int i = r - 1; i >= 0; i--) {
            for (int j = 0; j < c; j++) {
                if (g[i][j] && i < r - 1 && g[i + 1][j]) {
                    s[i][j] += s[i + 1][j] + 1;
                }
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (g[i][j] && j > 0 && g[i][j - 1]) {
                    w[i][j] += w[i][j - 1] + 1;
                }
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = c - 1; j >= 0; j--) {
                if (g[i][j] && j < c - 1 && g[i][j + 1]) {
                    e[i][j] += e[i][j + 1] + 1;
                }
            }
        }
        // casework 4 L shapes, 8 cases
        // NE, ES, SW, NW
        // EN, SE, WS, WN
        int cnt = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (n[i][j] && e[i][j]) {
                    int N = n[i][j] + 1;
                    int E = e[i][j] + 1;
                    cnt += min(N / 2, E) - 1; // subtract 1 because 1X2 and 2X1 are not L's
                    cnt += min(N, E / 2) - 1;
                }
                if (e[i][j] && s[i][j]) {
                    int E = e[i][j] + 1;
                    int S = s[i][j] + 1;
                    cnt += min(E / 2, S) - 1;
                    cnt += min(E, S / 2) - 1;
                }
                if (s[i][j] && w[i][j]) {
                    int S = s[i][j] + 1;
                    int W = w[i][j] + 1;
                    cnt += min(S / 2, W) - 1;
                    cnt += min(S, W / 2) - 1;
                }
                if (n[i][j] && w[i][j]) {
                    int N = n[i][j] + 1;
                    int W = w[i][j] + 1;
                    cnt += min(N / 2, W) - 1;
                    cnt += min(N, W / 2) - 1;
                }
            }
        }
        cout << "Case #" << tc << ": " << cnt << endl;
    }
    return 0;
}

// we need to find a one pass solution O(rc)
// store the longest n, e, s, w segment at each colored square O(4 * rc)
// now we can do one final parse assuming each one square is a corner
// and calculate the L shapes, if any, using the stored n, e, s, w segments O(rc)
// O(5 * rc) => O(rc)
/*
        // print dp stores
        cerr << "n " << endl;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cerr << n[i][j] << " ";
            }
            cerr << endl;
        }
        cerr << "e " << endl;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cerr << e[i][j] << " ";
            }
            cerr << endl;
        }
        cerr << "s " << endl;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cerr << s[i][j] << " ";
            }
            cerr << endl;
        }
        cerr << "w " << endl;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cerr << w[i][j] << " ";
            }
            cerr << endl;
        }
*/
