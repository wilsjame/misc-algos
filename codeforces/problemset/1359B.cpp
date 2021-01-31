#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        char a[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }

        int r = 0, c = 0;
        y = min(2 * x, y); // greedy

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '.') {
                    r++;
                }
                else {
                    c += (r / 2) * y + (r % 2) * x;
                    r = 0;
                }
            }
            c += (r / 2) * y + (r % 2) * x;
            r = 0;
        }
        cout << c << endl;
    }
        
    return 0;
}
