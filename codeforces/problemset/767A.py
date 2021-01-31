N = int(input())
A = list(map(int, input().split()))

next = N
has = [False] * (N + 1)

for dayv in A:
    has[dayv] = True
    if dayv == next:
        while has[next]:
            print(next, end = ' ')
            next = next - 1
    print()
