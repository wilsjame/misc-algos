#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool comp(string a, string b) {
    // lexicographically smaller
    return (a + b) < (b + a);
}

int main() {
    int n; 
    cin >> n;
    vector<string> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end(), comp);
    for (auto x : a) cout << x;
    return 0;
}

