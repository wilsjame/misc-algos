#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, k, res = 0;
    vector<int> a;
    cin >> n >> k;

    while (n--) {
        int s;
        cin >> s;
        a.push_back(s);
    }
    for (auto x : a) {
        if (x >= a[k - 1] && x > 0) {
            res++;
        }
        else {
            break;
        }
    }

    cout << res << endl;
    return 0;
}
