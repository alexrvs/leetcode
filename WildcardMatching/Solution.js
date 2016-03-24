/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function(s, p) {
    var l1 = s.length;
    var l2 = p.length;
    var i = 0;
    var j = 0;
    var saveIdx = 0;
    var starIdx = 0;
    var star = false;
    while (i < l1) {
        if (p[j] == '?') {
            i++;
            j++;
        } else if (p[j] == '*') {
            while (p[j] == '*') j++;
            star = true;
            starIdx = j;
            saveIdx = i;
        } else {
            if (s[i] == p[j]) {
                i++;
                j++;
            } else {
                if (star === true) {
                    i = ++saveIdx;
                    j = starIdx;
                } else {
                    return false;
                }
            }
        }
    }
    while (p[j] == '*') j++;
    return (i == l1 && j == l2);
};
