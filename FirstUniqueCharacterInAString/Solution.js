/**
 * @param {string} s
 * @return {number}
 */
var firstUniqChar = function(s) {
    var len = s.length;
    var i = 0;
    var cnt = new Array(26);
    for (i = 0; i < 26; i++) {
        cnt[i] = 0;
    }
    for (i = 0; i < len; i++) {
        cnt[s[i].charCodeAt() - 'a'.charCodeAt()]++;
    }
    for (i = 0; i < len; i++) {
        if (cnt[s[i].charCodeAt() - 'a'.charCodeAt()] == 1) return i;
    }
    return -1;
};
