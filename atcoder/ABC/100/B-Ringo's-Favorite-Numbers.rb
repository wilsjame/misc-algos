d,n = gets.chomp.split(" ").map(&:to_i)

def div100(x)
    ans = 0
    while x % 100 == 0
        x = x / 100
        ans += 1
    end
    return ans
end

ans = 0
(1..1e9.to_int).each do |i|
    if div100(i) == d
        ans = i
        n -= 1
    end
    if n == 0
        break
    end
end
puts ans
