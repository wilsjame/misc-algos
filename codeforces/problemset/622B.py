hh,mm = map(int, input().split(':'))
a = int(input())
hh += a // 60
mm += a % 60
if mm >= 60:
    hh += 1
hh %= 24
mm %= 60
print('%02d:%02d' % (hh,mm))
