#include <iostream>
using namespace std;

int main() {
    char a, b;
    cin >> a >> b;
    if (a == 'H' && b == 'H') {}
    else if (a == 'H' && b == 'D') {}
    else if (a == 'D' && b == 'H') {b = 'D';}
    else if (a == 'D' && b == 'D') {b = 'H';}
    cout << b;

    return 0;
}
