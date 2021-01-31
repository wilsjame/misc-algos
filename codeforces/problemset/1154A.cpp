#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    vector<int> v(4);
    int x1, x2, x3, x4, a, b, c;
    cin >> x1 >> x2 >> x3 >> x4;
    v[0] = x1; v[1] = x2; v[2] = x3; v[3] = x4;
    sort(v.rbegin(), v.rend());
    a = v[0] - v[1];
    b = v[0] - v[2];
    c = v[0] - v[3];

    cout << a << " " << b << " " << c << endl;
    
    return 0;
}
