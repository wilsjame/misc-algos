#include <iostream>
#include <vector>
using namespace std;

int main() {
    int A, B, C, X, ans = 0;
    cin >> A >> B >> C >> X;

    for (int a = 0; a <= A; a++) {
        for (int b = 0; b <= B; b++) {
            for (int c = 0; c <= C; c++) {
                int s = 500 * a + b * 100 + 50 * c;
                if (s == X) ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
