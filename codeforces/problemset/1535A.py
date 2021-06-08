t = int(input())
for _ in range(t):
    s1, s2, s3, s4 = map(int, input().split())
    if max(s1, s2) > min (s3, s4) and max(s3, s4) > min(s1, s2):
        print('YES')
    else:
        print('NO')
