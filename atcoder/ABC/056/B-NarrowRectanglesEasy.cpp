#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int W, a, b;
    cin >> W >> a >> b;
    if (abs(a - b) <= W)
        cout << 0;
    else
        cout << abs(a - b) - W;

    return 0;
}
