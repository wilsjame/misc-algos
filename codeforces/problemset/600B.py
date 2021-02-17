# NOTES
# use bisect instead of hard coding binary search
# if C++ use upper_bound
n,m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
a.append(1000000000+5)
a.sort()
for x in b:
    #binary search lowest number 
    #greater than x in a
    l = 0
    r = len(a)-1
    while l <= r:
        mid = (l+r)//2
        if a[mid] > x:
            r = mid-1
        elif a[mid] <= x:
            l = mid+1
        if a[mid] > x and a[mid-1] <= x:
            break;
    print(mid)
