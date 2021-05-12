#include <iostream>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    char b[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == '-') {
                b[i][j] = c;
            }
            else {
                (i + j) % 2 ? b[i][j] = 'W' : b[i][j] = 'B';
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << b[i][j];
        }
        cout << endl;
    }
    return 0;
}
