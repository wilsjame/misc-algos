import math
a = list(input())
b = list(input())
a_pos = a.count('+') - a.count('-')
b_pos = b.count('+') - b.count('-')
q = b.count('?')
d = abs(a_pos - b_pos)
if d > q: #or d % 2 != q % 2: 
    print(0)
else:
    # nCr ways of selecting n elements from a group of r elements
    # n^r permutations
    # expected value = ways of selecting needed '+' out of '?' / all permutations of '?'
    r = d + (q - d) / 2
    nCr = math.factorial(q) / (math.factorial(r) * math.factorial(q - r))
    ans = nCr / pow(2, q)
    print(ans)
