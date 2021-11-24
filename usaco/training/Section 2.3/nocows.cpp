/*
ID: jgwilso1
PROG: nocows
LANG: C++                 
*/
#include <iostream>
#include <cstdio>
using namespace std;

const int mxN = 200, mxD = 100, MOD = 9901;
int table[mxD + 1][mxN + 1];
int smalltrees[mxD + 1][mxN + 1];

int main() {
    freopen("nocows.in", "r", stdin);
    freopen("nocows.out", "w", stdout);
    
    int N, K; // nodes, depth
    cin >> N >> K;

    table[1][1] = 1;
    for (int i = 2; i <= K; i++) {
      for (int j = 1; j <= N; j += 2) { // state is depth i and j nodes

        // generate subtrees for this state
        for (int k = 1; k <= j - k - 1; k += 2) { 
          int lsub = k; 
          int rsub = j - k - 1;
          int c; // symmetric?
          lsub == rsub ? c = 1 : c = 2; 
          table[i][j] += c * (table[i - 1][lsub] * smalltrees[i - 2][rsub]);
          table[i][j] += c * (smalltrees[i - 2][lsub] * table[i - 1][rsub]);
          table[i][j] += c * (table[i - 1][lsub] * table[i - 1][rsub]);
          table[i][j] %= MOD;

        }
        // populate smaller trees (prefix sums) before going to next state
        for (int k = 1; k <= N; k += 2) {
          smalltrees[i - 1][k] = table[i - 1][k] + smalltrees[i - 2][k];
          smalltrees[i - 1][k] %= MOD;
        }

      }
    }
    cout << table[K][N] << endl;

    return 0;
}

// table[i][j] = cnt of trees of depth i with j nodes
// smalltrees[i - 2][j] = cnt of trees with depth less than i - 1 with j nodes
// ---------------------------------------------------------------------------
//
// a tree of N = j nodes and depth K = i can be split at the root resulting in two smaller subtrees;
// this is the smaller dp subproblem to build from
// we now have lsub, rsub, and the root node from where the split was made
// node count for lsub + rsub = j - 1, -1 for the excluded root node
//
// lets generate the subtrees by picking lsub to iterate (we could iterate rsub just as well)
// we iterate over some lsub node count k = 1, 2, ... what are the bounds of k?
// well, he have lsub + rsub = j - 1 nodes
// so if lsub has k nodes then rsub must have j - k - 1 nodes (k + rsub = j - 1 -> rsub = j - 1 - k)
// we iterate until both subtrees have the same node count k <= j - k - 1
// 
// for each k iteration we check if the lsub and rsub trees can contribute to table[i][j] 
//
// to create a tree of depth i atleast one of the subtrees must have depth i - 1 because when we connect the
// subtrees at the root the resultant depth is i - 1 + 1 = i
//
// 3 depth cases: 
// lsub = i - 1, rsub < i - 1 *
// lsub < i - 1, rsub = i - 1 * 
// lsub = i - 1, rsub = i - 1 **
// 
// * if the subtree depths are different we multiply the i - 1 depth trees by the number of smaller trees ie < i - 1
// ** if the subtrees depths are equal we multiply the i - 1 depth trees by the number of i - 1 depth trees
// sum these 3 cases to get the total number of subtree contributions to table[i][j]
//
// we keep a seperate table called smallertrees[][] to keep track of trees with depth less than i - 1
// ex) smallertrees[i - 2][k]      (kinda like a prefix sum)
// 
// finally,
// * if the subtree counts are different we multiply by 2 because the trees are not symmetric and can be flipped
// ** if the subtrees are symmetric (their counts are equal k = j - k - 1) we do not need to multiply by two
// finallyy, only odd node counts per problem statement: deg is 0 or 2
// O(K*N*N)
