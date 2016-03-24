# @param {String} s
# @param {String} p
# @return {Boolean}
def is_match(s, p)
    l1 = s.length
    l2 = p.length
    i = 0
    j = 0
    saveIdx = 0
    starIdx = 0
    star = false
    while i < l1 do
        if p[j] == '?' then
            i += 1
            j += 1
        elsif p[j] == '*' then
            j += 1 while p[j] == '*'
            starIdx = j
            saveIdx = i
            star = true
        else
            if s[i] == p[j] then
                i += 1
                j += 1
            else
                return false if star == false
                j = starIdx
                saveIdx += 1
                i = saveIdx
            end
        end
    end
    j += 1 while p[j] == '*'
    return (i == l1 && j == l2)
end
