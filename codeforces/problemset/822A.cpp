#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    int ans = 1;
    for (int s = 1; s <= min(A, B); s++)
        ans *= s;
    cout << ans;

    return 0;
}
