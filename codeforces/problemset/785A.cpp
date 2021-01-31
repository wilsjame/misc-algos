#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    int N;
    cin >> N;

    map<string, int> M;
    M["Tetrahedron"] =  4;
    M["Cube"] = 6;
    M["Octahedron"] = 8;
    M["Dodecahedron"] = 12;
    M["Icosahedron"] = 20;

    int ans = 0;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        ans += M[s];
    }
    cout << ans << endl;

    return 0;
}
