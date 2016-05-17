var myPow = function(x, n) {
    var remain = 1;
    var cur = x;
    if (n === 0) return 1;
    while (n > 1) {
        if (n % 2 === 1) remain *= cur;
        cur *= cur;
        n >>= 1;
    }
    return cur * remain;
}

/**
 * @param {number} n
 * @return {number}
 */
var integerBreak = function(n) {
    if (n == 2) return 1;
    if (n == 3) return 2;
    switch (n % 3) {
        case 0: return myPow(3, Math.floor(n / 3));
        case 1: return myPow(3, Math.floor(n / 3) - 1) * 4;
        case 2: return myPow(3, Math.floor(n / 3)) * 2;
    }
    return 0;
};
