# @param {String} secret
# @param {String} guess
# @return {String}
def get_hint(secret, guess)
    s = Array.new(10, 0)
    g = Array.new(10, 0)
    b = 0
    c = 0
    secret.chars.each_with_index do | c, i |
        b += 1 if secret[i] == guess[i]
        s[secret[i].to_i] += 1
        g[guess[i].to_i] += 1
    end
    s.each_with_index do | d, i |
        if s[i] < g[i]
            c += s[i]
        else
            c += g[i]
        end
    end
    c -= b
    return b.to_s + "A" + c.to_s + "B"
end
