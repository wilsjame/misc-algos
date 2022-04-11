print()
for case in range(int(input())):
    n = int(input())
    
    if n < 3:
        print(n)
        continue

    # greedy maximize number of digits
    # by always adding 1's and 2's
    digits = []
    if n & 1:
        digits.append(2)
    else:
        digits.append(1)

    while sum(digits) < n:
        # alternate 1's and 2's
        nxt = 1 if digits[-1] == 2 else 2
        digits.append(nxt)

    # edge cases
    if sum(digits) != n:
        assert(sum(digits) - n == 1)
        front = digits[0]
        if front == 1:
            del digits[0]
        elif front == 2:
            del digits[0]
            assert(digits[-1] == 2)
            digits.append(1)
    if digits[-1] > digits[0]:
        digits.reverse()

    assert(sum(digits) == n)
    #print(n, sum(digits), digits)
    print(*digits, sep='')

