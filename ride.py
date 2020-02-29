"""
PROG: ride
LANG: PYTHON3
"""
fin = open('ride.in', 'r')
fout = open('ride.out', 'w')
comet = fin.readline().strip('\n')
group = fin.readline().strip('\n')

chars = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
hashtable = {}
i = 0
for c in chars:
    i += 1
    hashtable[c] = i

comet_num = 1
group_num = 1
for c in comet:
    comet_num *= hashtable[c]
for c in group:
    group_num *= hashtable[c]

if group_num % 47 == comet_num % 47:
    verdict = 'GO'
else:
    verdict = 'STAY'
    
print(verdict)
fout.write(verdict + '\n')
fout.close()
