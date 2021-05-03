a = input().strip('{}').split(', ')
if a[0] == '':
    print(0)
else:
    myset = set(a)
    print(len(myset))
