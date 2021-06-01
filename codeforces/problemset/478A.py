c = list(map(int, input().split()))
if (sum(c) % 5 == 0 and sum(c) > 0) and max(c) <= sum(c):
    print(sum(c) // 5)
else:
    print(-1)
