n,k = map(int, input().split())
a = list(map(int, input().split()))
# sliding window O(n)
slow,fast = 0,0
cnt = {}
mx = -1
while fast < n:
    x = a[fast]
    cnt[x] = cnt.get(x,0)+1
    if len(cnt) <= k and fast-slow > mx:
        mx = fast-slow
        l,r = slow+1,fast+1
    elif len(cnt) > k:
        x = a[slow]
        cnt[x] -= 1
        if cnt[x] == 0:
            del cnt[x]
        slow += 1
    fast += 1
print(l,r)

# complete search O(n^2)
#dif = -1
#for i in range(n):
#    s = set()
#    for j in range(i,n):
#        s.add(a[j])
#        if len(s) <= k and j-i > dif:
#            dif = j-i
#            l,r = i+1, j+1
#        elif len(s) > k:
#            break;
#print(l,r)
