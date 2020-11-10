#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> S(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> S[i];
    }

    int dp[101][10005] = {};
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 10000; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - S[i] >= 0 && dp[i - 1][j - S[i]] == 1)
                dp[i][j] = 1;
            //printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
        }
    }

    int ans = 0;
    for (int score = 10000; score >= 0; score--) {
        if (dp[N][score] == 1 && score % 10 != 0) {
            ans = score;
            break;
        }
    }
    cout << ans << endl;

    return 0;
}

// straight-forward
/*
    int N, sum = 0;;
    cin >> N;
    vector<int> A(N);
    for (auto &k : A) { 
        cin >> k;
        sum += k;
    }

    // yeah this is kinda messy
    int ans = sum;
    sort(A.begin(), A.end());
    for (int i = 0; i < N && ans % 10 == 0; i++) {
        if (A[i] % 10 != 0) {
            ans -= A[i];                                        
        }
    }
    if (ans == sum && ans % 10 == 0) 
        cout << 0 << endl;
    else 
        cout << ans << endl;
*/
