#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int n = N, sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }

    cout << (N % sum == 0 ? "Yes" : "No") << endl;

    return 0;
}
