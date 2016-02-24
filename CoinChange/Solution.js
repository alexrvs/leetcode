/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
var coinChange = function(coins, amount) {
    var m = amount + 1;
    var cnts = new Array(m);
    var i = 0;
    var j = 0;
    var p = 0;
    cnts[0] = 0;
    for (i = 1; i < m; i++) cnts[i] = m;
    var n = coins.length;
    for (i = 0; i < n; i++) {
        if (coins[i] < m) cnts[coins[i]] = 1;
    }
    for (i = 1; i < m; i++) {
        for (j = 0; j < n; j++) {
            p = i - coins[j];
            if (p > 0 && cnts[p] + 1 < cnts[i]) {
                cnts[i] = cnts[p] + 1;
            }
        }
    }
    if (cnts[amount] == m) return -1;
    return cnts[amount];
};
