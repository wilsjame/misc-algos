import sys
sys.setrecursionlimit(int(10**6))
a, b = map(int, input().split())

# Binary Exponentiation O(log(n))
# even b: a^b = (a^(b/2))^2
# odd b: a^b = (a^(b/2))^2 * a
def binpow(a, b):
    result = 1
    while b > 0:
        if b % 2 == 1:
            result *= a
        a *= a
        b //= 2
    return result

    # recursive version
    '''
    if b == 0:
        return 1
    tmp = binpow(a, b // 2)
    if b % 2 == 0:
        result = tmp * tmp
    elif b % 2 == 1:
        result = tmp * tmp * a
    return result
    '''

print(binpow(a, b))
