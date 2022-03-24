# Challenge Nine
# Trick for divisible by 9.
# A number is divisible by
# 9 if the sum of its digits
# is divisible by 9.

T = int(input())
for t in range(1, T+1):
    N = input()
    reduced = 0
    for digit in N:
        reduced += int(digit)
        reduced %= 9
    add = 0
    if reduced > 0:
        add = 9 - reduced
    #print('add',  add)

    ans = [int(x) for x in N]
    if add == 0:
        ans.insert(1, add)
    else:
        for i in range(len(ans)):
            if ans[i] > add:
                ans.insert(i, add)
                break
            elif i == len(ans) - 1:
                ans.append(add)

    print(f"Case #{t}: {''.join(map(str,ans))}")

