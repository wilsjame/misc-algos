#include <iostream>
#include <map>
using namespace std;
int main() {
    int n;
    cin >> n;

    int h = 0;
    map<int, int> m;
    for (int x, i = 0; i < n; ++i){
        cin >> x;
        m[x]++;
        if (h < m[x]) {
            h = m[x];
        }
    }

    cout << h << " " << m.size() << endl;

    return 0;
}
