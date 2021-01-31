#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &a : A)
        cin >> a;

    vector<bool> has(N + 1, false);
    int next = N;
    for (int n : A) {
        has[n] = true;
        while (has[next]) {
            cout << next << " ";
            next--;
        }
        cout << endl;
    }
    
    return 0;
}
