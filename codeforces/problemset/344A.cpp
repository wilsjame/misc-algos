#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int n, res = 1;
    cin >> n;
    vector<string> a(n);
    for (auto &s : a) 
        cin >> s;
    for (int i = 1; i < n; i++) 
        if (a[i - 1] != a[i])
            res++;
    cout << res;

    return 0;
}
