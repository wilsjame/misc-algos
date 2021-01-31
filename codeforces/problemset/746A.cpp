#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    int ans = min({A, B / 2, C / 4}) * 7;
    cout << ans;
    
    return 0;
}
