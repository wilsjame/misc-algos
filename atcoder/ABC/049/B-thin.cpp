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

    for (int i = 0; i < H; i++) {
        for (int c = 0; c < 2; c++) {
            for (int j = 0; j < W; j++) {
                cout << A[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}
