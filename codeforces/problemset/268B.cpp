#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    // correct guesses
    int ans = n;
    for (int d = n; d > 0; d--) {
        // cost per guess at depth d
        int c = n - d + 1; 
        // incorrect guesses
        ans += (d - 1) * c; 
    }
    cout << ans << endl;
    return 0;
}
