# @param {String[]} strs
# @return {String}
def longest_common_prefix(strs)
    res = ""
    l = strs.length
    return res if l == 0
    return strs[0] if l == 1
    strs[0].chars.each_with_index do | c, i |
        strs.each do | str |
            if i >= str.length || str[i] != c
                return res
            end
        end
        res += c
    end
    return res
end
