n = int(input())
dict = {}
for _ in range(n):
    s = input()
    if s in dict:
        dict[s] += 1
        print(s + str(dict[s]))
    else:
        dict[s] = 0
        print('OK')
