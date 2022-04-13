for case in range(int(input())):
    a, b, c = map(int, input().split())

    # can a be multiplied?
    d = c - b
    need = b - d
    if need % a == 0 and need > 0:
        print('yes')
        continue

    # can b?
    d = (c - a) // 2
    need = a + d
    if (c - a) % 2 == 0 and need % b == 0 and need > 0:
        print('yes')
        continue

    # can c?
    d = b - a
    need = b + d
    if need % c == 0 and need > 0:
        print('yes')
        continue

    print('no')

