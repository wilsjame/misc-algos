for t in range(int(input())):
    n = int(input())
    s = input()
    stack = []
    for x in s:
        if x == '(':
            stack.append(x)
        elif x == ')' and len(stack) > 0:
            stack.pop()
    print(len(stack))
