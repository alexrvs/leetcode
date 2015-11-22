/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var rangeBitwiseAnd = function(m, n) {
    var i = 0;
    while (m != n) {
        m >>= 1;
        n >>= 1;
        i++;
    }
    return n << i;
};
