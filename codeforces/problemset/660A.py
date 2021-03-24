# Euclid's 
def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

n = int(input())
a = list(map(int, input().split()))
ans = []
for i in range(n - 1):
    ans.append(a[i])
    if gcd(a[i], a[i + 1]) != 1:
        ans.append(1)
ans.append(a[-1])
print(len(ans) - len(a))
print(*ans)
