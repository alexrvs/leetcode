/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
    var hl = haystack.length;
    var nl = needle.length;
    if (nl === 0) return 0;
    if (hl === 0 && nl === 0) return 0;
    var i = 0;
    var j = 0;
    for (i = 0; i < hl; i++) {
        j = 0;
        for (; j < nl; j++) {
            if (i + j >= hl) return -1;
            if (haystack[i + j] != needle[j]) {
                break;
            }
            if (j == nl - 1 && haystack[i + j] == needle[j]) return i;
        }
    }
    return -1;
};
