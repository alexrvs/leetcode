/**
 * @param {number[]} g
 * @param {number[]} s
 * @return {number}
 */
var findContentChildren = function(g, s) {
    g.sort(function(a, b) { return a - b; });
    s.sort(function(a, b) { return a - b; });
    let gi = g.length - 1;
    let si = s.length - 1;
    let cnt = 0;
    while (gi >= 0 && si >= 0) {
        if (g[gi] <= s[si]) {
            cnt++;
            si--;
        }
        gi--;
    }
    return cnt;
};