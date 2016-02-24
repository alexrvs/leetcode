# @param {Integer[]} coins
# @param {Integer} amount
# @return {Integer}
def coin_change(coins, amount)
    m = amount + 1
    cnts = Array.new(m, m)
    cnts[0] = 0
    coins.each do | c |
        cnts[c] = 1 if c < m
    end
    1.upto(m - 1) do | i |
        coins.each do | c |
            p = i - c
            cnts[i] = cnts[p] + 1 if p > 0 && cnts[i] > cnts[p] + 1
        end
    end
    return -1 if cnts[amount] == m
    return cnts[amount]
end
