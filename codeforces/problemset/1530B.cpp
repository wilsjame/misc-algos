#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int h, w;
        cin >> h >> w;
        int a[h][w] = {};
        // top and bottom rows
        for (int k = 0; k < w; k++) {
            a[0][k] = (k % 2 == 0);
            a[h - 1][k] = a[0][k]; 
        }
        // left and right columns
        for (int k = 1; k < h - 1; k++) {
            a[k][0] = a[k - 1][0] != 1 && a[k + 1][0] != 1;
            a[k][w - 1] = a[k][0];
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cout << a[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
