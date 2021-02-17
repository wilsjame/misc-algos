for t in range(int(input())):
    n = int(input())
    ans = 0
    for i in range(int((n-1)/2)+1):
        #top and bottom
        ans += i * 2 * (2*i+1)
        #sides
        ans += i * 2 * ((2*i+1)-2)
    print(ans)
