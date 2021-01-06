N = int(input())
A = list(map(int, input().split()))

B = A
A = sorted(A)
mid = N // 2
max_mid = A[mid]
min_mid = A[mid - 1]

for b in B:
    if b <= min_mid: # b < max_mid also valid
        print(max_mid)
    else:
        print(min_mid)
