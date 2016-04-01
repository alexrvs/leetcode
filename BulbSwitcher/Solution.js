/**
 * @param {number} n
 * @return {number}
 */
var bulbSwitch = function(n) {
    if (n < 2) return n;
    for (var i = 0; true; i++) {
        if (i * i > n) return i - 1;
    }
};
