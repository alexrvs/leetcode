/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    var size = prices.length;
    if (size < 2) return 0;
    var maxP = 0;
    var profit = 0;
    var minPrice = prices[0];
    for (var i = 1; i < size; i++) {
        if (prices[i] < minPrice) minPrice = prices[i];
        profit = prices[i] - minPrice;
        if (maxP < profit) maxP = profit;
    }
    return maxP;
};
