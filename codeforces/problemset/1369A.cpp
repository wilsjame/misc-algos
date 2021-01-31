#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        n % 4 ? cout << "NO\n" : cout << "YES\n";
    }
    return 0;
}
