t = int(input())
for _ in range(t):
        n = int(input())
        a = sorted(list(map(int, input().split())))
        guest = 0;
        for i in range(n):
            if i + 1 >= a[i]:
                guest = i + 1
        print(guest + 1)
