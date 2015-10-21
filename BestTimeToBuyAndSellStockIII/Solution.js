/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    var l = prices.length;
    if (l < 2) return 0;
    var forward = [];
    var backward = [];
    var maxProfit = 0;
    var minPrice = prices[0];
    var profit = 0;
    for (var i = 0; i < l; i++) {
        if (prices[i] < minPrice) minPrice = prices[i];
        profit = prices[i] - minPrice;
        if (maxProfit < profit) maxProfit = profit;
        forward.push(maxProfit);
    }
    maxProfit = 0;
    var maxPrice = prices[l - 1];
    for (i = l - 1; i >= 0; i--) {
        if (maxPrice < prices[i]) maxPrice = prices[i];
        profit = maxPrice - prices[i];
        if (maxProfit < profit) maxProfit = profit;
        backward.push(maxProfit);
    }
    backward.reverse();
    for (i = 0; i < l; i++) {
        profit = forward[i] + backward[i];
        if (maxProfit < profit) maxProfit = profit;
    }
    return maxProfit;
};
