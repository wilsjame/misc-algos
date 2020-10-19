#include <iostream>
using namespace std;

#define ll long long

int main() {
    int N;
    cin >> N;
    // complimentary counting
    // total positions choose 2
    // knight attack positions are 2 X 3 and 3 X 2 rectangles
    // for an 8 X 8 board there are 7 * 6 + 7 * 6 of these
    // so 2(n-1)(n-2) and we have two knights so each rectangle
    // counts as two attack positions -> 2*2(n-1)(n-2)
    // 4(n-1)(n-2) total attack positions
    for (int k = 1; k <= N; k++) {
        ll positions = k * k;
        ll combinations = (positions * (positions - 1)) / 2;
        ll attack_positions = 4*(k - 1)*(k - 2);
        cout << combinations - attack_positions << endl;
    }

    return 0;
}
