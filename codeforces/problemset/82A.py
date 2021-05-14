n = int(input())
q = ['Sheldon', 'Leonard', 'Penny', 'Rajesh', 'Howard']
p = 0
cnt = 0
while True:
    steps = 0
    for i in range(1, 6):
        cnt += pow(2, p)
        if cnt >= n:
            print(q[steps])
            exit()
        steps += 1
    p += 1
