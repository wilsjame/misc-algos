#include <iostream>
using namespace std;

int main() {
    int X;
    cin >> X;

    int ans = 1, diff = 1005;
    for (int b = 2; b * b <= X; b++) {
        int bp = b;
        while (bp * b  <= X) 
            bp *= b;
        if (X - bp < diff) {
            diff = X - bp;
            ans = bp;
        }
    }
    cout << ans << endl;

    return 0;
}
