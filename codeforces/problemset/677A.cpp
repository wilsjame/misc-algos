#include <iostream>
using namespace std;
int main() {
    int n, h, ans = 0;
    cin >> n >> h;
    for (int a, i = 0; i < n; i++) {
        cin >> a;
        a > h ? ans += 2 : ans++;
    }
    cout << ans << endl;
    return 0; 
}
