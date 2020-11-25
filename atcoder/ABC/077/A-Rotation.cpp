#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s1, s2, r1, r2;
    cin >> s1 >> s2;

    r1 = s1, r2 = s2;
    reverse(r1.begin(), r1.end());
    reverse(r2.begin(), r2.end());

    cout << (s1 == r2 && s2 == r1 ? "YES" : "NO") << endl;

    return 0;
}
