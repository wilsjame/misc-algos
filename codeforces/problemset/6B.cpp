#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map> // set would also be fine
using namespace std;
int main() {
    map<char,int> h;
    vector<pair<int,int>> v;
    char c;
    int n, m, x, y;
    cin >> n >> m >> c;
    char a[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == c) {
                v.push_back(make_pair(i, j));
            }
        }
    }

    for (auto p : v) {
        x = p.first;
        y = p.second;

        if (x + 1 < n && a[x + 1][y] != '.') {
            h[a[x + 1][y]]++;
        }
        if (y + 1 < m && a[x][y + 1] != '.') {
            h[a[x][y + 1]]++;
        }
        if (x - 1 >= 0 && a[x - 1][y] != '.') {
            h[a[x - 1][y]]++;
        }
        if (y -1 >= 0 && a[x][y - 1] != '.') {
            h[a[x][y - 1]]++;
        }
    }
    h.erase(c);
    cout << h.size() << endl;

    return 0;
}
