#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int a;
        cin >> a;
        // regular polygon:
        // exterior angles sum to 360
        // 180 - interior angle gives exterior angle
        // so, (180 - a) * n = 360
        // and because number of sides is a whole number...
        360 % (180 - a) == 0 ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}
