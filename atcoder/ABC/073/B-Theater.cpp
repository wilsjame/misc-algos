#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int L, R, ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> L >> R;
        ans += (R - L) + 1;
    }

    cout << ans << endl;
    return 0;
}
