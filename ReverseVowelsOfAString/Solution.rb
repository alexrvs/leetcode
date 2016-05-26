def isVowel(c)
    return true if c.downcase == 'a'
    return true if c.downcase == 'e'
    return true if c.downcase == 'i'
    return true if c.downcase == 'o'
    return true if c.downcase == 'u'
    return false
end

# @param {String} s
# @return {String}
def reverse_vowels(s)
    l = 0
    r = s.length - 1
    while l < r do
        if isVowel(s[l]) && isVowel(s[r]) then
            c = s[l]
            s[l] = s[r]
            s[r] = c
            l += 1
            r -= 1
        else
            l += 1 if false == isVowel(s[l])
            r -= 1 if false == isVowel(s[r])
        end
    end
    return s
end
