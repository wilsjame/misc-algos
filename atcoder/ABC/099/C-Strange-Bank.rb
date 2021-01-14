n = gets.to_i
INF = 1e9
maxn = 1e5 

# valid withdrawals
w = [1]
z = 1
while 6**z <= maxn
    w.push(6**z)
    z+=1
end
z = 1
while 9**z <= maxn
    w.push(9**z)
    z+=1
end

# dp[val] stores optimal solution for val 
dp = [INF]*(n+1)
dp[0] = 0
(n+1).times do |value|
    w.each do |withdraw|
        if value - withdraw >= 0
            dp[value] = [dp[value-withdraw]+1, dp[value]].min
        end
    end
end
puts dp[n]
