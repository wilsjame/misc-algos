#include <iostream>
using namespace std;

int main() {
    int X, A, B;
    cin >> X >> A >> B;

    int z = B - A;

    if (z <= 0) 
        cout << "delicious\n";
    else if (z <= X)
        cout << "safe\n";
    else 
        cout << "dangerous\n";

    return 0;
}
