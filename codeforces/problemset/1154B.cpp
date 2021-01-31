#include <iostream>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end()); 
    // unique end - begin = size
    v.resize(unique(v.begin(), v.end()) - v.begin());

    int res;
    if (v.size() == 1) {
        res = 0;
    }
    else if (v.size() > 3) {
        res = -1;
    }
    else if (v.size() == 3) {
        v[2] - v[1] == v[1] - v[0] ? res = v[2] - v[1] : res = -1;
    }
    else { // size is 2
        assert(v.size() == 2);
        // midpoint is integer if sum is even
        (v[0] + v[1]) % 2 == 0 ? res = v[1] - (v[1] + v[0]) / 2 : res = v[1] - v[0];
    }
    cout << res << endl;

    return 0;
} 
