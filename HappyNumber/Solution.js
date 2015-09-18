/**
 * @param {number} n
 * @return {boolean}
 */
var isHappy = function(n) {
    var used = [];
    while (n > 100 || used.indexOf(n) == -1) {
        if (n <= 100) used.push(n);
        var sum = 0;
        while (n > 0) {
            var d = n % 10;
            sum += d * d;
            n = Math.floor(n / 10);
        }
        if (sum == 1) return true;
        n = sum;
    }
    return false;
};
