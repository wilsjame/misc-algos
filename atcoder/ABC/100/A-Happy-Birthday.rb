a,b = gets.chomp.split(" ").map(&:to_i)
if a > 8 or b > 8
    puts ":("
else
    puts "Yay!"
end
