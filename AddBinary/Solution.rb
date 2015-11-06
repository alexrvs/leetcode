# @param {String} a
# @param {String} b
# @return {String}
def add_binary(a, b)
    al = a.length
    bl = b.length
    l = al
    l = bl if al < bl
    i = 0
    c = 0
    res = []
    while i < l do
        ad = 0
        ad = a[al - 1 - i].to_i if al - 1 >= i
        bd = 0
        bd = b[bl - 1 - i].to_i if bl - 1 >= i
        d = ad + bd + c
        c = d / 2
        d = d % 2
        res << d.to_s
        i += 1
    end
    if c == 1
        res << "1"
    end
    return res.reverse.join
end
