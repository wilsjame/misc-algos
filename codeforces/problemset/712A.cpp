#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &a : A) 
        cin >> a;

    vector<int> ans;
    for (int i = 0; i + 1 < N; i++) 
        ans.push_back(A[i] + A[i + 1]);
    ans.push_back(A[N - 1]);
    for (auto k : ans) 
        cout << k << " ";

    return 0;
}

