# @param {String} s
# @return {Integer}
def first_uniq_char(s)
    cnt = Array.new(26, 0)
    s.chars.each do | c |
        cnt[c.ord - 'a'.ord] += 1
    end
    s.chars.each_with_index do | c, i |
        return i if cnt[c.ord - 'a'.ord] == 1
    end
    return -1
end
