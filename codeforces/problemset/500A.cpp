#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, target;
    cin >> n >> target;
    vector<int> a(30005, 0);
    for (int i = 1; i <= n - 1; i++) 
        cin >> a[i];

    int pos = 1;
    while (pos < target) {
        pos += a[pos];
    }
    pos == target ? cout << "YES" : cout << "NO";

    return 0;
}
