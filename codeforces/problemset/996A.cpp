#include <iostream>
using namespace std;

int main() {
    //greedy
    int res = 0, n;
    cin >> n;

    res += n / 100;
    n %= 100;
    res += n / 20;
    n %= 20;
    res += n / 10;
    n %= 10;
    res += n / 5;
    n %= 5;
    res += n / 1;

    cout << res << endl;

    return 0;
}
