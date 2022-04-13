from collections import Counter
for case in range(int(input())):
    n, k = map(int, input().split())
    cnt = Counter(list([ch for ch in input()]))

    # Greedy, use up all the pairs first.
    # Then we get to add at most 1 if we
    # have enough odds.
    pairs = 0
    odds = 0
    for c, v in cnt.items():
        pairs += v // 2
        cnt[c] -= (v // 2) * 2
        odds += cnt[c]
    res = (pairs // k) * 2
    rem = (pairs % k) * 2
    odds += rem
    if odds >= k:
        res += 1
    print(max(1, res))

