n = int(input())
s = input()

# prefix sums
sumw = [0]*n
sume = [0]*n
for i in range(n):
    if s[i] == 'W':
        sumw[i] += 1
    if i != 0:
        sumw[i] += sumw[i-1]
for i in reversed(range(n)):
    if s[i] == 'E':
        sume[i] += 1
    if i != n-1:
        sume[i] += sume[i+1]

ans = 3e5+5
for i in range(n):
    l = 0 if i == 0 else sumw[i-1]
    r = 0 if i == n-1 else sume[i+1]
    ans = min(ans, l+r)
print(ans)
