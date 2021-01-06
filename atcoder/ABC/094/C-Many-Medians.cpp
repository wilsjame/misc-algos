#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &a : A)
        cin >> a;

    vector<int> B = A;
    sort(A.begin(), A.end());
    int mid = N / 2;
    int min_mid = A[mid - 1];
    int max_mid = A[mid];

    for (int b : B) {
        if (b <= min_mid) // b < max_mid also valid
            cout << max_mid << endl;
        else 
            cout << min_mid << endl;
    }

    return 0;
}
