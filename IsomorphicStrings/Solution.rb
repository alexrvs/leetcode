# @param {String} s
# @param {String} t
# @return {Boolean}
def is_isomorphic(s, t)
    m1 = {}
    m2 = {}
    s.chars.each_with_index do | cs, i |
        ct = t[i]
        if m1.include? cs
            return false if ct != m1[cs]
        else
            m1[cs] = ct
        end
        if m2.include? ct
            return false if cs != m2[ct]
        else
            m2[ct] = cs
        end
    end
    return true
end
