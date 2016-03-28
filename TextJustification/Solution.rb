def add_spaces(str, i, n, l, left_just)
    if n > 0 && i < n then
        spaces = left_just ? 1 : (l / n + (i < l % n ? 1 : 0))
        while spaces != 0 do
            str += " "
            spaces -= 1
        end
    end
    return str
end

def connect(words, from, to, len, max_width, left_just)
    str = ""
    from.upto(to) do | i |
        str += add_spaces(words[i], i - from, to - from, max_width - len, left_just)
    end
    while str.length < max_width do
        str += " "
    end
    return str
end

# @param {String[]} words
# @param {Integer} max_width
# @return {String[]}
def full_justify(words, max_width)
    res = []
    i = 0
    from = 0
    l = 0
    while i < words.length do
        if l + words[i].length + (i - from) > max_width then
            res << connect(words, from, i - 1, l, max_width, false)
            from = i
            l = 0
        end
        l += words[i].length
        i += 1
    end
    res << connect(words, from, i - 1, l, max_width, true)
    return res
end
