s = list(input())
for i in range(len(s)):
    cnt = 0
    for j in range(i + 1, len(s)):
        if s[j] == s[i]:
            cnt += 1
        else:
            break
    if cnt > 0:
        if i > 0:
            before = s[i - 1]
        else:
            before = s[i]
        if i + cnt < len(s) - 1:
            after = s[i + cnt + 1]
        else:
            after = s[i + cnt]
        change = None
        for ch in list('abcdefghijklmnopqrstuvwxyz'):
            if ch != s[i] and ch != before and ch != after:
                change = ch
                break
        cnt += 1
        i -= 1
        for j in range(cnt // 2):
            i += 2
            s[i] = change
print(*s, sep='')
