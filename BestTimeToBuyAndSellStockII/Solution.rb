# @param {Integer[]} prices
# @return {Integer}
def max_profit(prices)
    return 0 if prices.length < 2
    profit = 0
    prices.each_with_index do |p, i|
        profit += prices[i] - prices[i - 1] if i > 0 and prices[i - 1] < prices [i]
    end
    return profit
end
