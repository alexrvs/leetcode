# @param {Integer[]} prices
# @return {Integer}
def max_profit(prices)
    l = prices.length
    return 0 if l < 2
    forward = []
    backward = []
    maxProfit = 0
    minPrice = prices[0]
    prices.each do | p |
        minPrice = p if p < minPrice
        profit = p - minPrice
        maxProfit = profit if maxProfit < profit
        forward << maxProfit
    end
    maxProfit = 0
    maxPrice = prices[l - 1]
    prices.reverse.each do | p |
        maxPrice = p if maxPrice < p
        profit = maxPrice - p
        maxProfit = profit if maxProfit < profit
        backward << maxProfit
    end
    backward = backward.reverse
    maxProfit = 0
    forward.each_with_index do | p, i |
        profit = forward[i] + backward[i]
        maxProfit = profit if maxProfit < profit
    end
    return maxProfit
end
