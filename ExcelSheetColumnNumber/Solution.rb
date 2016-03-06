# @param {String} s
# @return {Integer}
def title_to_number(s)
    sum = 0
    s.chars.each do | c |
        sum = sum * 26 + (c.ord - 'A'.ord + 1)
    end
    return sum
end
