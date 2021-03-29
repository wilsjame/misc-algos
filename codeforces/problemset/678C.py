def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

def lcm(a, b):
    return (a * b) // gcd(a, b)

n, a, b, p, q = map(int, input().split())
a_cnt = n // a
b_cnt = n // b
ab_cnt = n // lcm(a, b)
if p > q:
    b_cnt -= ab_cnt
else:
    a_cnt -= ab_cnt
ans = p * a_cnt + q * b_cnt
print(ans)
