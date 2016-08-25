/**
 * @param {string} s
 * @return {string[]}
 */
var findRepeatedDnaSequences = function(s) {
    var cnt = {};
    var res = [];
    var i = 0;
    var j = 0;
    var len = s.length;
    for (i = 0; i < 10; i++) {
        for (j = i; j + 10 <= len; j += 10) {
            var sub = s.slice(j, j + 10);
            var c = 0;
            if (cnt[sub] !== undefined) {
                c = cnt[sub];
            }
            cnt[sub] = c + 1;
        }
    }
    for (var key in cnt) {
        if (cnt[key] > 1) res.push(key);
    }
    return res;
};
