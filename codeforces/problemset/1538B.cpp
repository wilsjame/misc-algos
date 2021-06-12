#include <iostream>
#include <vector>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int sum = 0;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        if (sum % n == 0) {
            int target = sum / n;
            int cnt = 0;
            int over = 0;
            int under = 0;
            for (int &x : a) {
                if (x > target) {
                    over += x - target;
                    cnt += 1;
                }
                else if (x < target) {
                    under += target - x;
                }
            }
            if (over == under) {
                cout << cnt << endl;
            }
            else {
                cout << -1 << endl;
            }
        }
        else {
            cout << -1 << endl;
        }
    }
    return 0;
}
