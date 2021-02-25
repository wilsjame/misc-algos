""" messy but works :/ """
# palindrome all letter sums must be even and 0 or 1 odd sum allowed
s = input()
cnt = [0]*26
for letter in s:
    cnt[ord(letter) - ord('a')] += 1
# find odd counts
odd = []
for letter in range(26):
    if cnt[letter] % 2:
        odd.append(letter)
# greedy swap odds
for i in range(len(odd)//2):
    l_up = odd[i]
    l_down = odd[-(i+1)]
    cnt[l_up] += 1
    cnt[l_down] -= 1
m = []

""" construct palindrome """
# one odd in middle
for i in range(26):
    if cnt[i] % 2:
        m.append(chr(i + ord('a')))
        cnt[i] -= 1
# remaining are even
p = []
for i in range(26):
    while cnt[i] > 0:
        p.append(chr(i + ord('a')))
        cnt[i] -= 2
print(''.join(p) + ''.join(m) + ''.join(reversed(p)))
