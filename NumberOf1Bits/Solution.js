/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var hammingWeight = function(n) {
    var mask = 0x0001;
    var num = 0;
    for (var i = 0; i < 32; i++) {
        if ((n & mask) !== 0) num++;
        mask = mask << 1;
    }
    return num;
};
