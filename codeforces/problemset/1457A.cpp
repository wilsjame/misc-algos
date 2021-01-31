#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M, R, C;
        cin >> N >> M >> R >> C;

        // time is the farthest cell from R, C
        // which will be one of the corners
        int x, y;
        x = max(C - 1, M - C);
        y = max(R - 1, N - R);
        cout << x + y << endl;
    }

    return 0;
}
