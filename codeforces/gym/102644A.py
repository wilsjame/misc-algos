n, p = input().split()
n = int(n)
p = float(p)
# initially happy
prob_happy = 1
# binary exponentiation
while n > 0:
    if n % 2 == 1:
        prob_happy = p * (1 - prob_happy) + (1 - p) * prob_happy
    p = p * (1 - p) + (1 - p) * p
    n //= 2
print(prob_happy)
