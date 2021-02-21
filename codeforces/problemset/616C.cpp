#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
#define MX 1005

int n, m, id;
int color[MX][MX];
int cnt[MX*MX];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

char A[MX][MX];

void dfs(int i, int j) {
    color[i][j] = id;
    cnt[id]++;
    for (int k = 0; k < 4; k++) {
        int y = i + dy[k];
        int x = j + dx[k];
        // (y,x) must be in bounds, '.', and not colored
        if (y >= 0 && y < n && x >= 0 && x < m && A[y][x] == '.' && !color[y][x]) {
            dfs(y, x);
        }
    }
    return;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            A[i][j] = s[j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // not colored yet
            if (A[i][j] == '.' && !color[i][j]) {
                id++;
                dfs(i, j);
            }
        }
    }

    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cerr << color[i][j];
        }
        cerr << endl;
    }
    */

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == '.') {
                cout << '.';
            }
            else if (A[i][j] == '*') {
                // connected components
                int res = 1;
                set<int> cc;
                for (int k = 0; k < 4; k++) {
                    int y = i + dy[k];
                    int x = j + dx[k];
                    // (y,x) must be in bounds and a not yet counted connected component
                    if (y >= 0 && y < n && x >= 0 && x < m && A[y][x] == '.') {
                        id = color[y][x];
                        if (!cc.count(id)) {
                            res += cnt[id];
                        }
                        cc.insert(id);
                    }
                }
                cout << res % 10;
            }
        }
        cout << endl;
    }

    return 0;
}
