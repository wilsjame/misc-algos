#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string O, E;
    cin >> O >> E;
    reverse(O.begin(), O.end());
    reverse(E.begin(), E.end());
    string ans;
    while (!O.empty() || !E.empty()) {
        if (!O.empty()) {
            ans += O.back();
            O.pop_back();
        }
        if (!E.empty()) {
            ans += E.back();
            E.pop_back();
        }
    }
    cout << ans;

    return 0;
}
