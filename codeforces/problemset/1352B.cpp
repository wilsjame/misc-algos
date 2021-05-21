#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int o = n - (1 * (k - 1));
        int e = n - (2 * (k - 1));
        if ((o % 2 == 0 || o < 1) && (e % 2 || e < 1)) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
            if (o % 2) {
                for (int i = 0; i < k - 1; i++) {
                    cout << 1 << " ";
                }
                cout << o << endl;
            }
            else if (e % 2 == 0) {
                for (int i = 0; i < k - 1; i++) {
                    cout << 2 << " ";
                }
                cout << e << endl;
            }
        }
    }
    return 0;
}
