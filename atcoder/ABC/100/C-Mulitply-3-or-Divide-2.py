n = int(input())
a = list(map(int, input().split()))

def div2(x):
    cnt = 0;
    while x & 1 == 0:
        x = x >> 1
        cnt += 1
    return cnt

ans = 0;
for x in a:
    ans += div2(x)
print(ans)
