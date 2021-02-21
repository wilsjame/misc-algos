#include <iostream>
#include <vector>
#include <algorithm>
#define print(x) cerr << #x << " is " << x << endl;
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        vector<int> row(m);
        for (int j = 0; j < m; j++) {
            cin >> row[j];
        }
        ans = max(ans, *min_element(row.begin(), row.end()));
    }
    cout << ans << endl;

    return 0;
}

