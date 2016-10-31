/**
 * @param {number} n
 * @return {number}
 */
var arrangeCoins = function(n) {
    let l = 0;
    while (n >= l) {
        n -= l;
        l++;
    }
    return l - 1;
};