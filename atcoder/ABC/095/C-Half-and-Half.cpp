#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int minv = min(X, Y);
    int minxy = min(A + B, 2 * C);
    int minx = min(A, 2 * C);
    int miny = min(B, 2 * C);
    X -= minv;
    Y -= minv;

    int ans = minv * minxy + X * minx + Y * miny;
    cout << ans;

    return 0;
}
