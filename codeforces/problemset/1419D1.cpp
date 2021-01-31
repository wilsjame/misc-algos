#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n), cheap(n);
    for (auto &k : a) cin >> k;
    sort(a.begin(), a.end());

    // number of cheap ice spheres
    int N;
    n <= 2 ? N = 0 : N = n / 2;
    if (n <= 2) {
        cout << N << endl;
        for (auto k : a) cout << k << " ";
    }
    else {
        // number of cheap ice spheres
        if (n % 2)
            cout << N << endl;
        else
            cout << N - 1 << endl;
        for (int j= 1, i = 0; i < N; j += 2, i++) 
            cheap[j] = a[i];
        for (int j = 0, i = N; i < n; j += 2, i++)
            cheap[j] = a[i];
        for (auto k : cheap) cout << k << " ";
    }

    return 0;
}
