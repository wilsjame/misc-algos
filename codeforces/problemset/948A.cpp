#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    //freopen("input.txt", "r", stdin);
    vector<pair<int, int>> s;
    int R, C;
    cin >> R >> C;
    char a[R][C];

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'S') {
                s.push_back({i, j});
            }
            else if (a[i][j] == '.') {
                a[i][j] = 'D';
            }
            
        }
    }

    bool safe = true;
    for (auto pt : s) {
        if (a[max(pt.first - 1, 0)][pt.second] == 'W' || a[min(pt.first + 1, R - 1)][pt.second] == 'W' || a[pt.first][max(pt.second - 1, 0)] == 'W' || a[pt.first][min(pt.second + 1, C - 1)] == 'W') {
            cout << "NO" << endl;
            safe = false;
            break;
        }
    }
    if (safe) {
        cout << "YES" << endl;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cout << a[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}
