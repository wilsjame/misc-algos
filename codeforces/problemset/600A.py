import re
a = []
b = []
for x in re.split(r',|;',input()):
    if x == '0':
        a.append(x)
    elif x and x[0] != '0' and x.isdigit():
        a.append(x)
    else:
        b.append(x)
if not a:
    print('-')
else:
    print('"' + ','.join(a) + '"')
if not b:
    print('-')
else:
    print('"' + ','.join(b) + '"')
