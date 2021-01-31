#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        bool found = false;
        for (int i = 1; i + 1 < n; i++) {
            if (a[i - 1] < a[i] && a[i] > a[i + 1]) {
                cout << "YES" << endl;
                cout << i << " " << i + 1 << " " << i + 2 << endl; 
                found = true;
                break;
            }
        }
        if (!found) cout << "NO" << endl;
    }

    return 0;
}
