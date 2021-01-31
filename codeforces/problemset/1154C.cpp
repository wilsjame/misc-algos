#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;

    int full = min({a1 / 3, a2 / 2, a3 / 2});
     
    a1 -= full * 3;
    a2 -= full * 2;
    a3 -= full * 2;
    full *= 7;

    vector<int> a = {a1, a2, a3};
    vector<int> w = {1, 2, 3, 1, 3, 2, 1};

    int res = full;
    for (int day = 0; day < 7; day++) {
        vector<int> b = a;
        int cur = day, add = 0;

        while (1) {
            if (b[w[cur] - 1] == 0) {
                break;
            }
            else {
                b[w[cur] - 1]--;
            }
            add++;
            cur = (cur + 1) % 7; 

            res = max(res, full + add);
        }

    }
    cout << res << endl;

    return 0;
}
