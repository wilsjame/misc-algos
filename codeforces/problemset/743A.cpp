#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    vector<char> v(N + 1);
    for (int i = 1; i <= N; i++) 
        cin >> v[i];

    cout << (v[A] == v[B] ? 0 : 1);

    return 0;
}
