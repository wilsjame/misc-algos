#include <iostream>
#include <vector>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> A(H, vector<char> (W));
    for (auto &row : A)
        for (auto &a : row)
            cin >> a;

    for (int i = 0; i < W + 2; i++) cout << '#';
    cout << endl;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (j == 0) cout << '#';
            cout << A[i][j];
            if (j == W - 1) cout << '#';
        }
        cout << endl;
    }
    for (int i = 0; i < W + 2; i++) cout << '#';

    return 0;
}
