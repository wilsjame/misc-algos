# O(|s|*m)
a = list(input())
for _ in range(int(input())):
        l,r,k = map(int, input().split())
        k %= r-l+1
        a = a[:l-1] + a[r-k:r] + a[l-1:r-k] + a[r:]
print(*a,sep='')
