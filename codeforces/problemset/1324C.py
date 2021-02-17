for t in range(int(input())):
    s = list(input())
    r = [0]
    for i in range(len(s)):
        if s[i] == 'R':
            r.append(i+1)
    r.append(len(s)+1)
    d = []
    mx = 0
    for i in range(1,len(r)):
        mx = max(mx, r[i]-r[i-1])
    print(mx)
