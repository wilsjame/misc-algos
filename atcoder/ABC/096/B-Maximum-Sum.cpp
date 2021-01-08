#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int A, B, C, K;
    cin >> A >> B >> C >> K;

    int ans;
    ans = A + B + C + max({A, B, C}) * ((1 << K) - 1);
    cout << ans << endl;

    return 0;
}
