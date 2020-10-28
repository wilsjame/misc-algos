#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;

    int l = S.size();
    int dp[(int)1e6] = {};

    dp[0] = 1;
    for (int i = 0; i < l; i++) {
        if (dp[i] == 0) continue;
        if (i + 5 <= l && S.substr(i, 5) == "erase") dp[i + 5] = 1;
        if (i + 5 <= l && S.substr(i, 5) == "dream") dp[i + 5] = 1;
        if (i + 6 <= l && S.substr(i, 6) == "eraser") dp[i + 6] = 1;
        if (i + 7 <= l && S.substr(i, 7) == "dreamer") dp[i + 7] = 1;
    }

    if (dp[l] == 1)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
