/**
 * @param {number} k
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(k, prices) {
    let size = prices.length;
    if (k >= (size >> 1)) {
        let res = 0;
        for (let i = 1; i < size; i++) {
            let diff = prices[i] - prices[i - 1];
            if (diff > 0) res += diff;
        }
        return res;
    }
    
    let dp = [];
    for (let i = 0; i <= k; i++) {
        dp[i] = new Array(size);
        for (let j = 0; j < size; j++) {
            dp[i][j] = 0;
        }
        if (i > 0) {
            let tmp = -prices[0];
            for (let j = 1; j < size; j++) {
                dp[i][j] = Math.max(dp[i][j - 1], prices[j] + tmp);
                tmp = Math.max(tmp, dp[i - 1][j - 1] - prices[j]);
            }
        }
    }
    return dp[k][size - 1];
};