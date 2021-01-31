#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int sq = sqrt(n);
        cout << sq - 1 + (n - 1) / sq << endl;
    }

    return 0;
}
