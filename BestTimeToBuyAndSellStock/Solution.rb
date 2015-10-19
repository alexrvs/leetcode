# @param {Integer[]} prices
# @return {Integer}
def max_profit(prices)
    return 0 if prices.length < 2
    max_p = 0
    profit = 0
    min_price = prices[0]
    prices.each do |p|
        min_price = p if p < min_price
        profit = p - min_price
        max_p = profit if max_p < profit
    end
    return max_p
end
