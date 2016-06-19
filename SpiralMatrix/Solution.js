var loop = function(matrix, si, sj, rl, cl, dir, result) {
    if (rl === 0 || cl === 0)
            return;
    var i = 0;
    if (dir === 0) {
        for (i = sj; i < sj+cl; i++) {
            result.push(matrix[si][i]);
        }
        loop(matrix, si+1, i-1, rl-1, cl, 1, result);
    } else if (dir == 1) {
        for (i = si; i < si+rl; i++) {
            result.push(matrix[i][sj]);
        }
        loop(matrix, i-1, sj-1, rl, cl-1, 2, result);
    } else if (dir == 2) {
        for (i = sj; i > sj-cl; i--) {
            result.push(matrix[si][i]);
        }
        loop(matrix, si-1, i+1, rl-1, cl, 3, result);
    } else if (dir == 3) {
        for (i = si; i > si-rl; i--) {
            result.push(matrix[i][sj]);
        }
        loop(matrix, i+1, sj+1, rl, cl-1, 0, result);
    }
    return;
};

/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
    var result = [];
    var m = matrix.length;
    if (m === 0) return result;
    var n = matrix[0].length;
    loop(matrix, 0, 0, m, n, 0, result);
    return result;
};
