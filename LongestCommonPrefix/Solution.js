/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    var res = "";
    var l = strs.length;
    if (l === 0) return res;
    if (l === 1) return strs[0];
    var l0 = strs[0].length;
    for (var idx = 0; idx < l0; idx++) {
        var c = strs[0][idx];
        for (var i = 1; i < l; i++) {
            if (idx > strs[i].length || strs[i][idx] != c) {
                return res;
            }
        }
        res += c;
    }
    return res;
};
