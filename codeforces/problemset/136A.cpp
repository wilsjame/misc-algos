#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n];
    for (int k, i = 0; i < n; i++) {
        cin >> k;
        a[k - 1] = i + 1;
    }
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}
