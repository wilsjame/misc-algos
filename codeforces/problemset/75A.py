#TODO lamda
a = int(input())
b = int(input())
aa = []
bb = []
cc = []
for i in str(a):
    if i != '0':
        aa.append(i)
for i in str(b):
    if i != '0':
        bb.append(i)
for i in str(a + b):
    if i != '0':
        cc.append(i)
a = int(''.join(map(str, aa)))
b = int(''.join(map(str, bb)))
c = int(''.join(map(str, cc)))

if a + b == c:
    print('YES')
else:
    print('NO')
