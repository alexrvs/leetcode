/**
 * @param {number} n
 * @return {number}
 */
var integerReplacement = function(n) {
    if (n == 1) return 0;
    if (n % 2 === 0) {
        return 1 + integerReplacement(Math.floor(n / 2));
    }
    var n1 = integerReplacement(n + 1);
    var n2 = integerReplacement(n - 1);
    return 1 + (n1 < n2 ? n1 : n2);
};
