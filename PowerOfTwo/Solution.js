/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfTwo = function(n) {
    var cnt = 0;
    while (n > 0) {
        if ((n & 0x0001) !== 0) cnt++;
        n >>= 1;
    }
    if (cnt == 1) return true;
    return false;
};
