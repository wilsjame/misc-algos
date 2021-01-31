#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        // sum of two odds is even approach
        bool found = false;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] % 2 == 0 && !found) {
                cout << 1 << endl << i + 1 << endl;
                found = true;
            }
        }
        if (!found) {
            if (n == 1) {
                cout << -1 << endl;
            }
            else {
                cout << 2 << endl << "1 2" << endl;
            }
        }
    }
    return 0;
}

/*
        bool found = false;
        vector<int> b = {};
        for (int i = 0; i < n && !found; i++) {
            b.clear();
            for (int j = i, sum = 0; j < n; j++) {
                b.push_back(j + 1);
                sum += a[j];
                if (sum % 2 == 0) {
                    found = true;
                    break;
                }
            }
        }
        if (found) {
            cout << b.size() << endl;
            for (auto x : b) {
                cout << x << " ";
            }
        }
        else {
            cout << -1;
        }
        cout << endl;
        */
