#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int X, Y;
    cin >> X >> Y;

    set<int> a, b, c;
    a = {1, 3, 5, 7, 8, 10, 12};
    b = {4, 6, 9, 11};
    c = {2};

    if ((a.count(X) && a.count(Y)) || (b.count(X) && b.count(Y)) || (b.count(X) && b.count(Y))) 
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
