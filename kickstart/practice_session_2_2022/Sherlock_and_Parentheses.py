#import sys
#sys.stdin = open('in.txt', 'r')

def solve():
    (L, R) = tuple(map(int, input().split()))
    # Compute number of balanced parentheses.
    n = min(L, R)
    # Compute number of ways to count the balanced parentheses.
    ans = (n*(n+1))//2
    print(ans)

T = int(input())
for t in range(T):
    print(f"Case #{t+1}: ", end='')
    solve()
