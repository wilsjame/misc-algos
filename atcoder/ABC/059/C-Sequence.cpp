#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

#define ll long long

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (auto &k : A) 
        cin >> k;

    ll sum_1 = 0, sum_2 = 0, cnt_1 = 0, cnt_2 = 0;

    // two cases, sign change to -1 or 1 
    //Ae+ Ae- Ae+ ...
    //Ae- Ae+ Ae- ...
    for (int i = 0; i < N; i++) {
        sum_1 += A[i];
        sum_2 += A[i];

        if (i % 2 == 0) {
            if (sum_1 >= 0) {
                cnt_1 += sum_1 + 1;
                sum_1 = -1;
            }
            if (sum_2 <= 0) {
                cnt_2 += abs(sum_2) + 1;
                sum_2 = 1;
            }
        }
        else {
            if (sum_1 <= 0) {
                cnt_1 += abs(sum_1) + 1;
                sum_1 = 1;
            }
            if (sum_2 >= 0) {
                cnt_2 += sum_2 + 1;
                sum_2 = -1;
            }
        }
        //cout << sum_1 << " " << sum_2 << " " << cnt_1 << " " << cnt_2 << endl;
    }
    cout << min(cnt_1, cnt_2) << endl;

    return 0; 
}

