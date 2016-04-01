# @param {Integer} n
# @return {Integer}
def bulb_switch(n)
    return n if n < 2
    1.upto(n) do | i | if i * i > n then return i - 1 end end
end
