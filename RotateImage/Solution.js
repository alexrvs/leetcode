/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    var l = matrix.length;
    var h = l >> 1;
    var w = h;
    if (l % 2 !== 0) w++;
    for (var i = 0; i < h; i++) {
        for (var j = 0; j < w; j++) {
            var tmp = matrix[i][j];
            matrix[i][j] = matrix[l - 1 - j][i];
            matrix[l - 1 - j][i] = matrix[l - 1 - i][l - 1 - j];
            matrix[l - 1 - i][l - 1 - j] = matrix[j][ l - 1 - i];
            matrix[j][ l - 1 - i] = tmp;
        }
    }
};
