#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<vector<int>> v;
    for (int i = 0; i < n; i++) {
        vector<int> pr(2);
        cin >> pr[0] >> pr[1];
        v.push_back(pr);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans += v[i][0] == v[j][1];
        }
    }
    cout << ans << endl;
    return 0;
}
