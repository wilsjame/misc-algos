for case in range(int(input())):
        n = int(input())
        s = list(input())
        # two pointer
        ans = 0
        slow = 0
        while slow < n:
            fast = min(n-1, slow+1)
            faster = min(n-1, fast+1)
            if slow < fast and s[slow] == '0' and s[fast] == '0':
                #print(f'00 at {slow} {fast} {faster}')
                ans += 2
            if slow < fast and fast < faster and s[slow] == '0' and s[fast] == '1' and s[faster] == '0':
                #print(f'010 at {slow} {fast} {faster}')
                ans += 1
            slow += 1
        print(ans)

