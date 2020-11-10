#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &k : A)
        cin >> k;

    if (N == 1) {
        cout << 0 << endl;
    }
    else {
        sort(A.begin(), A.end());
        cout << A[N -1] - A[0] << endl;
    }
        
    return 0;
}

