#TODO use bit operations
n, p = map(int, input().split())
a = []
# ignore last value because we know the last apple count
# needs to be 1 with a 'halfplus' sale to reach 0
for _ in range(n-1):
    a.append(input())
input()

# find apple count by going backwards
apples = 1
for x in reversed(a):
    if x == 'half':
        apples *= 2
    elif x == 'halfplus':
        apples *= 2
        apples += 1

# find cost by going forwards
a.append('halfplus')
ans = 0
for x in a:
    if x == 'half':
        ans += p*(apples/2)
        apples /= 2
    elif x == 'halfplus':
        ans += p*(apples/2)
        apples //= 2
assert apples == 0
print(int(ans))
