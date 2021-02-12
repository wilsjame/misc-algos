n = gets.to_i
a = gets.chomp.split(" ").map(&:to_i)
b = gets.chomp.split(" ").map(&:to_i)

ans = "I become the guy."
(1..n).each do |i|
  if !a.drop(1).include?(i) and !b.drop(1).include?(i)
    ans = "Oh, my keyboard!"
    break
  end
end
puts ans
