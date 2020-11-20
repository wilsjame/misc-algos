#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    // one try
    int time = 1900 * M + 100 * (N - M);

    // each M takes two tries because of the 1/2 probability
    for (int i = 0; i < M; i++) {
        time *= 2;
    }

    cout << time << endl;

    return 0;
}
