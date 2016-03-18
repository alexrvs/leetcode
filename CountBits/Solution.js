/**
 * @param {number} num
 * @return {number[]}
 */
var countBits = function(num) {
    var res = new Array(num + 1);
    res[0] = 0;
    var n = 1;
    for (var i = 1; i <= num; i++) {
        if (i - n >= n) n <<= 1;
        res[i] = 1 + res[i - n];
    }
    return res;
};
