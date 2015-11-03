/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    var size = s.length;
    var len = 0;
    for (var i = size - 1; i >= 0; i--) {
        var c = s[i];
        if (c === ' ') {
            if (len === 0) continue;
            return len;
        }
        len++;
    }
    return len;
};
