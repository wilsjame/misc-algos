/* 
 Fenwick tree i.e. binary indexed tree BIT implementation

 Prefix sum array:
 - query range sum: O(1)
 - update value: O(n)
 - make: O(n)

 Fenwick tree (BIT):
 - query range sum: O(logn)
 - update value: O(logn)
 - make: O(n)
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> A = {1, 4, 2, 1, 3, 5, 1, 2, 3};
vector<int> prefix_sum(A.size());
vector<int> tree(A.size() + 1);

/* populate Fenwick tree O(n) linear time :D */
vector<int> make(vector<int> ar) {
    // copy of original array (1-based idx)
    vector<int> fenw = {0};
    fenw.insert(fenw.end(), ar.begin(), ar.end());
    // update immediate parent, find p by taking last set bit
    // and adding it to itself. 00101 - > 00110
    for (int i = 1; i < fenw.size(); i++) {
        int p = i + (i & -i); // index to parent
        if (p < fenw.size()) {
            fenw[p] = fenw[p] + fenw[i];
        }
    }
    return fenw;
}

/* compute prefix sum from 1 to i [1, i] (1-based idx) */
int sum(int i) {
    int s = 0;
    while (i > 0) {
        s += tree[i];
        i -= i & -i; // flip last set bit 00101 -> 00100
    }
    return s;
}

/* add value x at position i (1-based idx) */
void add(int i, int x) {
    // propagate change to end of tree
    while (i < tree.size()) {
        tree[i] += x;
        i += i & -i; // add last set bit 00100 -> 01000
    }
}

int main() {
    /* original array */ 
    cout << "A" << endl;
    for (auto k : A) {
        cout << k << " ";
    } cout << endl;

    /* prefix sum array */
    cout << "prefix sum array" << endl;
    prefix_sum[0] = A[0];
    for (int i = 1; i < A.size(); i++) {
        prefix_sum[i] = prefix_sum[i - 1] + A[i];
    }
    // prefix sums
    for (auto k : prefix_sum) {
        cout << k << " ";
    } cout << endl;
    // range sum [4, 7] (0-based idx)
    cout << prefix_sum[7] - prefix_sum[3] << endl;

    /* Fenwick tree BIT */
    cout << "Fenwick tree (BIT)" << endl;
    tree = make(A);
    for (auto k : tree) {
        cout << k << " ";
    } cout << endl;
    // prefix sums
    for (int i = 1; i < tree.size(); i++) {
        cout << sum(i) << " ";
    } cout << endl;
    // range sum [5, 8] (1-based idx)
    cout << sum(8) - sum(4) << endl;
    // add -1 to idx 8 (1-based idx)
    add(8, -1);
    cout << sum(8) - sum(4) << endl;

    return 0;
}
