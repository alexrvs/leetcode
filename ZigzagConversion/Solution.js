/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function(s, numRows) {
    if (numRows == 1) return s;
    var step = 2 * (numRows - 1)
        var l = s.length;
    var res = "";
    for (var i = 0; i < numRows; i++) {
        for (var j = 0; j - i < l; j += step) {
            if (i !== 0 && i != numRows - 1) {
                if (j - i > 0) {
                    res += s[j - i];
                }
            }
            if (j + i < l) {
                res += s[j + i];
            }
        }
    }
    return res;
};
