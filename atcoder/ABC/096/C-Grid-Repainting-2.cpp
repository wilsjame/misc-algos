#include <iostream>
using namespace std;

char A[55][55];

int main() {
    int H, W;
    cin >> H >> W;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) 
            cin >> A[i][j];
    }

    int cnt = 0;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (A[i][j] == '#' && A[i][j - 1] != '#' && A[i][j + 1] != '#' && A[i - 1][j] != '#' && A[i + 1][j] != '#') cnt++;
        }
    }
    if (cnt == 0) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
