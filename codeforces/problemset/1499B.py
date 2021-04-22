t = int(input())
for _ in range(t):
    s = list(input())
    ans = True
    ones = False
    zeros = True
    skip = True
    for x in s:
        if x == '0' and zeros is True:
            skip = True
            continue
        elif x == '0' and ones is True and skip is True:
            skip = False
            continue
        elif x == '0' and ones is True and skip is False:
            ans = False
            break
        elif x == '1' and zeros is True and skip is True:
            skip = False
            continue
        elif x == '1' and zeros is True and skip is False:
            if ones is False:
                ones = True
                zeros = False
                skip = True
                continue
            else:
                ans = False
                break
        elif x == '1' and ones is True:
            skip = True
            continue
        elif x == '1' and ones is False and skip is False:
            ans = False
            break
    if ans is False:
        print('NO')
    else:
        print('YES')
