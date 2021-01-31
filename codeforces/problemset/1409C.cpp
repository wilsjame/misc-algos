#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, X, Y;
        cin >> n >> X >> Y; // X < Y

        int diff = Y - X;
        vector<int> a(n), best(n, 1e9 + 5);

        // brute force all positions of x and y for sequence size n: O(n^2)
        // for each x and y position fill the arithmetic sequence: O(n)
        // => O(n^3)
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                // partitions are the spaces between values in the sequence
                // a,b has one partition, a,b,c has two partitions
                int partitions = j - i;

                if (diff % partitions == 0) {
                    int idx, partition_size = diff / partitions;
                    a[j] = Y;

                    // build sequence to the right
                    idx = j + 1;
                    while (idx < n) {
                        a[idx] = a[idx - 1] + partition_size;
                        idx++;
                    }
                    // build sequence to the left
                    idx = j - 1;
                    while (idx >=0) {
                        a[idx] = a[idx + 1] - partition_size;
                        idx--;
                    }

                    assert(a[i] == X);
                    if (a[0] > 0 && a[n - 1] < best[n - 1]) {
                        best = a;
                    }
                }
            }
        }
        for (auto k : best) {
            cout << k << " ";
        }
        cout << endl;
    }
    
    return 0;
}
