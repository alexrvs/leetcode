/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isIsomorphic = function(s, t) {
    var l = s.length;
    var m1 = {};
    var m2 = {};
    for (var i = 0; i < l; i++) {
        var cs = s[i];
        var ct = t[i];
        if (cs in m1) {
            if (ct != m1[cs]) return false;
        } else {
            m1[cs] = ct;
        }
        if (ct in m2) {
            if (cs != m2[ct]) return false;
        } else {
            m2[ct] = cs;
        }
    }
    return true;
};
