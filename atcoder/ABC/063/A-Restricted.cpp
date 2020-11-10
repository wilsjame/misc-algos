#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    if (A + B >= 10) 
        cout << "error" << endl;
    else 
        cout << A + B << endl;

    return 0;

}
