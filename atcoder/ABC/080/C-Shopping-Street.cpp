#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int N, F[101][11], P[101][11];
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 10; j++)
            cin >> F[i][j];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 11; j++) 
            cin >> P[i][j];

    int res = INT_MIN ; // -(1<<30)

    // bit mask total combinations of Joisino's shop hours 2^10 = 1024
    for (int mask = 1; mask < (1<<10); mask++) {
        int sum = 0;

        for (int i = 0; i < N; i++) {
            int common = 0;
            for (int j = 0; j < 10; j++) {
                // is the mask bit set and the other shop open?
                if (mask & (1 << j) && F[i][j]) 
                    common++;
            }
            sum += P[i][common];
        }

        res = max(res, sum);
    }

    cout << res << endl;

    return 0;
}
