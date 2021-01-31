// beautiful matrix
#include <iostream>
using namespace std;
int main() {
    int res = 0;

    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            int x;
            cin >> x;
            if (x == 1) {
                res += abs(3 - i) + abs(3 - j);
            }

        }
    }
    cout << res << endl;

    return 0;
}
