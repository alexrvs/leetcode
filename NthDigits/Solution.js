/**
 * @param {number} n
 * @return {number}
 */
var findNthDigit = function(n) {
    var ndigits = 1;
    var upper = 9;
    var from = 1;
    var dupper = 9;
    while (n > dupper) {
        n -= dupper;
        ndigits += 1;
        from = upper + 1;
        upper = from * 10 - 1;
        dupper = ndigits * (upper - from + 1);
    }
    from += Math.floor((n - 1) / ndigits);
    n = (n - 1) % ndigits;
    digits = [];
    while (from > 0) {
        digits.push(from % 10);
        from = Math.floor(from / 10);
    }
    return digits[ndigits - 1 - n];
};
