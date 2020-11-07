#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

#define ll long long

int main() {
    int N;
    cin >> N;
    vector<ll> V(N);
    for (auto &k : V) 
        cin >> k;

    vector<ll> prefix_sum(N), A(N);
    ll cnt_1 = 0, cnt_2 = 0;

    //Ve+ Ve- Ve+ ...
    A = V;
    prefix_sum[0] = A[0];
    if (prefix_sum[0] <= 0) {
        A[0] += (abs(prefix_sum[0]) + 1);
        cnt_1 += (abs(prefix_sum[0]) + 1);
        prefix_sum[0] = A[0];
    }
        //printf("prefix_sum[%d] = %lld\n", 0, prefix_sum[0]);
    for (int i = 1; i < N; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + A[i];
        if (i % 2 && prefix_sum[i] >= 0) {
            A[i] -= (prefix_sum[i] + 1);
            cnt_1 += (prefix_sum[i] + 1);
            prefix_sum[i] = prefix_sum[i - 1] + A[i];
        }
        else if (i % 2 == 0 && prefix_sum[i] <= 0) {
            A[i] += (abs(prefix_sum[i]) + 1);
            cnt_1 += (abs(prefix_sum[i]) + 1);
            prefix_sum[i] = prefix_sum[i - 1] + A[i];
        }
        //printf("prefix_sum[%d] = %lld\n", i, prefix_sum[i]);
    }

    cerr << "\n---\n";

    //Ve- Ve+ Ve- ...
    A = V;
    prefix_sum[0] = A[0];
    if (prefix_sum[0] >= 0) {
        A[0] -= (prefix_sum[0] + 1);
        cnt_2 += (prefix_sum[0] + 1);
        prefix_sum[0] = A[0];
    }
        //printf("prefix_sum[%d] = %lld\n", 0, prefix_sum[0]);
    for (int i = 1; i < N; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + A[i];
        if (i % 2 && prefix_sum[i] <= 0) {
            A[i] += (abs(prefix_sum[i]) + 1);
            cnt_2 += (abs(prefix_sum[i]) + 1);
            prefix_sum[i] = prefix_sum[i - 1] + A[i];
        }
        else if (i % 2 == 0 && prefix_sum[i] >= 0) {
            A[i] -= (prefix_sum[i] + 1);
            cnt_2 += (prefix_sum[i] + 1);
            prefix_sum[i] = prefix_sum[i - 1] + A[i];
        }
        //printf("prefix_sum[%d] = %lld\n", i, prefix_sum[i]);
    }


    //printf("cnt_1: %lld cnt_2: %lld\n", cnt_1, cnt_2);
    cout << min(cnt_1, cnt_2) << endl;

    return 0; 
}

