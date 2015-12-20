# @param {String} s
# @param {Integer} num_rows
# @return {String}
def convert(s, num_rows)
    return s if num_rows == 1
    step = 2 * (num_rows - 1)
    res = ""
    l = s.length
    i = 0
    while i < num_rows do
        j = 0
        while j - i < l do
            if i == 0 || i == num_rows - 1 then
                res += s[j + i] if j + i < l
            else
                res += s[j - i] if j - i > 0
                res += s[j + i] if j + i < l
            end
            j += step
        end
        i += 1
    end
    return res
end
