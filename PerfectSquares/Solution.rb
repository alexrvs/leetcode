# @param {Integer} n
# @return {Integer}
def num_squares(n)
    d1 = []
    d2 = []
    i = 1
    while i * i <= n do d1 << i*i; i += 1 end
    return 1 if d1.include? n
    d1.each do |i| d1.each do |j| d2 << i+j end end
    return 2 if d2.include? n
    d1.each do |i| return 3 if d2.include? n - i end
    return 4
end
