/**
 * @param {number} n
 * @return {number}
 */
var lastRemaining = function(n) {
    var start = 1;
    var diff = 1;
    var time = 1;
    while (n > 1) {
        if (time % 2 == 1 || n % 2 == 1) {
            start += diff;
        }
        time++;
        n -= (n + 1) >> 1;
        diff <<= 1
    }
    return start;
};