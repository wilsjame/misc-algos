n = gets.to_i
a = gets.chomp.split(" ").map(&:to_i)

def div2(x)
    cnt = 0
    while x & 1 == 0
        x = x >> 1
        cnt += 1
    end
    return cnt
end

ans = 0
a.each do |val|
    ans += div2(val)
end
print(ans)
