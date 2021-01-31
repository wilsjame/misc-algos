#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt = 0;
    for (auto &x : a) {
        cin >> x;
        if (x == 1) cnt++;
    }
    int res = 0;
    for (int prev = -1, i = 0; i < n && cnt > 0; i++) {
        if (a[i] == 1) {
            res++;
            cnt--;
        }
        else if (a[i] == 0 && prev == 1) {
            res++;
        }
        prev = a[i];
    }
    cout << res << endl;

    return 0;
}

