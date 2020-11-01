#include <iostream>
using namespace std;

int main() {
    int W, a, b;
    cin >> W >> a >> b;
    if (a + W < b)
        cout << b - (a + W);
    else if (b + W < a)
        cout << a - (b + W);
    else 
        cout << 0;

    return 0;
}
