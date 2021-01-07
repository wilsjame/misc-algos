#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string S;
    cin >> S;
    int ans = 700;
    ans += 100 * count(S.begin(), S.end(), 'o');
    cout << ans;

    return 0;
}
