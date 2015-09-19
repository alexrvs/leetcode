/**
 * @param {number} n
 * @return {number}
 */
var trailingZeroes = function(n) {
    var zeroes = 0;
    while (n > 0) {
        n = Math.floor(n/5);
        zeroes += n;
    }
    return zeroes;
};
