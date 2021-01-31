#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    string S;
    cin >> S;
    int ans = 0;
    char pos = 'a';
    for (char next : S) { 
        ans += min(abs(next - pos), 26 - abs(next - pos));
        pos = next;
    }
    cout << ans;

    return 0;
}
