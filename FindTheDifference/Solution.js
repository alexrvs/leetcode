/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
var findTheDifference = function(s, t) {
    var cnt = {};
    var i = 0;
    for (i = 0; i < t.length; i++) {
        if (t[i] in cnt) {
            cnt[t[i]] += 1;
        } else {
            cnt[t[i]] = 1;
        }
    }
    for (i = 0; i < s.length; i++) {
        cnt[s[i]] -= 1;
    }
    for (var key in cnt) {
        if (cnt[key] == 1) return key;
    }
    return 'a';
};
