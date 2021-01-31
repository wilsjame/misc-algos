#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
    double n, m, a;
    cin >> n >> m >> a;

    double  ans;
    ans = ceil(n / a) * ceil(m / a);
    cout << fixed << setprecision(0);
    cout << ans << endl;

    return 0;
}
