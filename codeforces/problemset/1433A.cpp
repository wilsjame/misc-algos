#include <iostream>
#include <string>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        string S;
        cin >> S;
        int n, ans = 0;
        n = S.size();
        if (S[0] - '0' > 1) {
            int x;
            x = S[0] - '0';
            ans += (x - 1) * 10;
        }
        if (n == 1)
            ans += 1;
        else if (n == 2) 
            ans += 3;
        else if (n == 3) 
            ans += 6;
        else if (n == 4)
            ans += 10;
        cout << ans << endl;
    }
    return 0;
}
