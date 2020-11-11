#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(auto &a : A) 
        cin >>a;

    deque<int> B;

    for (int i = 0; i < N; i++) {
        if (i % 2 == 0)
            B.push_back(A[i]);
        else 
            B.push_front(A[i]);
    }
    if (N % 2)
        reverse(B.begin(), B.end());

    for (auto z : B) 
        cout << z << " ";

    return 0;
}
    
