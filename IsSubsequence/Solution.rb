# @param {String} s
# @param {String} t
# @return {Boolean}
def is_subsequence(s, t)
    return true if s.length == 0
    idx = 0
    t.chars.each do | c |
        if c == s[idx] then
            idx += 1
            return true if idx == s.length
        end
    end
    return false
end
