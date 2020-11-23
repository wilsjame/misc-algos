#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;

    sort(S.begin(), S.end());
    sort(T.rbegin(), T.rend());

    cout << (S < T ? "Yes" : "No") << endl;

    return 0;
}
