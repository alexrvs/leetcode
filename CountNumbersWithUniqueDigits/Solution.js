/**
 * @param {number} n
 * @return {number}
 */
var countNumbersWithUniqueDigits = function(n) {
    var sum = 0;
    var temp = 9;
    for (var i = 0; i <= n && i <= 10; i++) {
        if (i === 0) sum += 1;
        else if (i === 1) sum += 9;
        else {
            temp *= Math.max(0, 11 - i);
            sum += temp;
        }
    }
    return sum;
};
