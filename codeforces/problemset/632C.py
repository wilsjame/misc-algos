def comp(a, b):
    if a+b < b+a:
        return -1
    else:
        return 1

from functools import cmp_to_key
l = []
for _ in range(int(input())):
    l.append(input())
print(''.join(sorted(l, key=cmp_to_key(comp))))
