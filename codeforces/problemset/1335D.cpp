#include <iostream>
#include <string>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int a[9][9];
        for (int i = 0; i < 9; i++) {
            string line;
            cin >> line;
            for (int j = 0; j < 9; j++) {
                a[i][j] = line[j] - '0';
            }
        }
        // 9 changes
        int dx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
        int dy[] = {7, 1, 4, 8, 5, 2, 0, 6, 3};
        for (int i = 0; i < 9; i++) {
            int x = dx[i];
            int y = dy[i];
            a[x][y] == 1 ? a[x][y] = 2 : a[x][y] = 1;
        }
        // print
        //cerr << endl;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << a[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
