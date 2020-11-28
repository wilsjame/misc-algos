#include <iostream>
#include <set>
using namespace std;

int main() {
    int N;
    cin >> N;

    set<char> count;
    for (int i = 0; i < N; i++) {
        char hina_arare;
        cin >> hina_arare;
        count.insert(hina_arare);
    }
    
    cout << (count.size() == 3 ? "Three" : "Four") << endl;

    return 0;
}
