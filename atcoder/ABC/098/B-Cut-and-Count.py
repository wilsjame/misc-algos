n = int(input())
s = input()

ans = 0
for i in range(len(s)):
    # intersection
    ans = max(ans, len(set(s[:i]) & set(s[i:])))
print(ans)
