d,n = map(int, input().split())

def div100(x):
    ans = 0;
    while x % 100 == 0:
        x = x / 100
        ans += 1
    return ans

for i in range(1, int(1e9)):
    if div100(i) == d:
        ans = i;
        n -= 1
    if n == 0:
        break;
print(ans)
