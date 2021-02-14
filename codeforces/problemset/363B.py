n,k = map(int, input().split())
h = list(map(int, input().split()))

#O(n-k)
sums = [sum(h[:k])]
for i in range(k,n):
    sums.append((sums[-1]-h[i-k])+h[i])
print(sums.index(min(sums))+1)

#O(n*k)
#mn = int(1e11)
#for i in range(n):
#    bag = []
#    for j in range(k):
#        if i+j > n-1:
#            break;
#        else:
#            bag.append(h[i+j])
#    if len(bag) == k:
#        #print(i+1, sum(bag))
#        if sum(bag) < mn:
#            mn = sum(bag)
#            ans = i+1
#print(ans)
