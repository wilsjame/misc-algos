#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        char g[n][m];
        // chess board
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i&1) == (j&1)) {
                    g[i][j] = 'B';
                }
                else {
                    g[i][j] = 'W';
                }
            }
        }
        // color one more square
        int area = n * m;
        if (!(area&1)) {
            g[0][1] = 'B';
        }
        // print
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << g[i][j];
            }
            cout << endl;
        }

        // TRICK!
        // paint entire board black expect for one corner white
        // thus always 1 W neighbored by 2 B
    }

    return 0;
}
