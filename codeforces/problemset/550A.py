x = input()
a = []
b = []
for i in range(len(x)-1):
    if x[i] + x[i+1] == 'AB':
        a.append(i)
    if x[i] + x[i+1] == 'BA':
        b.append(i)

if not a or not b:
    print("NO")
    quit()

if max(a) - min(b) > 1 or max(b) - min(a) > 1:
    print("YES")
else:
    print("NO")
