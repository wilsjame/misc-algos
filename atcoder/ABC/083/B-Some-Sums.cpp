#include <iostream>
using namespace std;

int sum(int n) {
    int ans = 0;
    while (n) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

int main() {
    int N, A, B, ans = 0;
    cin >> N >> A >> B;

    for (int n = A; n <= N; n++) {
        if (sum(n) >= A && sum(n) <= B) 
            ans += n;
    }

    cout << ans << endl;

    return 0;
}
