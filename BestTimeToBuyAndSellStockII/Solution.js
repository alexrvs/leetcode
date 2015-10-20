/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    if (prices.length < 2) return 0;
    var profit = 0;
    for (var i = 0; i < prices.length; i++) {
        if (prices[i - 1] < prices[i]) {
            profit += prices[i] - prices[i - 1];
        }
    }
    return profit;
};
