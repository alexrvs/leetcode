# @param {String} pattern
# @param {String} str
# @return {Boolean}
def word_pattern(pattern, str)
    psize = pattern.length
    words = str.split
    wsize = words.length
    return false if psize != wsize
    m = {}
    pattern.chars.each_with_index do |c, i|
        if m[c] == nil
            return false if m.values.include? words[i]
            m[c] = words[i]
        elsif m[c] != words[i]
            return false
        end
    end
    return true
end
