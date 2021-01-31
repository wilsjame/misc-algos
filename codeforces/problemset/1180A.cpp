#include <iostream>
using namespace std;
int main() {
    int n, ans = 0;
    cin >> n;

    // sum of odds => n^2
    // nth odd => 2n+1
    ans = 2 * (n * n) - 2 * n + 1;

    cout << ans << endl;

    return 0;
}
