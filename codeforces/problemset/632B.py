#TODO check out Lewin's Python solution https://codeforces.com/blog/entry/43493
n = int(input())
p = list(map(int, input().split()))
s = input()
ogmx = 0
premx = [0] * (n+1)
sufmx = [0] * (n+1)
# sum if no change
for i in range(n):
    if s[i] == 'B':
        ogmx += p[i]
# prefix sums
premx[0] = ogmx
for i in range(n):
    if s[i] == 'B':
        premx[i+1] = premx[i] - p[i]
    elif s[i] == 'A':
        premx[i+1] = premx[i] + p[i]
# suffix sums
sufmx[n] = ogmx
for i in range(n-1,-1,-1):
    if s[i] == 'B':
        sufmx[i] = sufmx[i+1] - p[i]
    elif s[i] == 'A':
        sufmx[i] = sufmx[i+1] + p[i]
print(max(max(premx), max(sufmx)))
