/**
 * @param {string} s
 * @return {number}
 */
var titleToNumber = function(s) {
    var sum = 0;
    for (var i = 0; i < s.length; i++) {
        sum = sum * 26 + (s[i].charCodeAt() - 'A'.charCodeAt() + 1);
    }
    return sum;
};
