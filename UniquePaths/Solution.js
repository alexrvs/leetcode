/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var uniquePaths = function(m, n) {
    var p = [];
    for (var i = 0; i < m; i++) {
        var r = [1];
        p.push(r);
        for (var j = 1; j < n; j++) {
            if (i === 0) {
                p[i].push(1);
            } else {
                p[i].push(p[i - 1][j] + p[i][j - 1]);
            }
        }
    }
    return p[m - 1][n - 1];
};
