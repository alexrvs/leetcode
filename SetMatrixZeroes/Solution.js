/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var setZeroes = function(matrix) {
    var r = matrix.length;
    if (r === 0) return;
    var c = matrix[0].length;
    var i = 0;
    var j = 0;
    var firstRow = 1;
    var firstCol = 1;
    for (i = 0; i < r; i++) {
        if (matrix[i][0] === 0) firstCol = 0;
        for (j = 0; j < c; j++) {
            if (matrix[i][j] === 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
                if (i === 0) firstRow = 0;
            }
        }
    }
    for (i = 1; i < r; i++) {
        for (j = 1; j < c; j++) {
            if (matrix[i][0] === 0 || matrix[0][j] === 0) matrix[i][j] = 0;
        }
    }
    if (firstRow === 0) for (j = 0; j < c; j++) matrix[0][j] = 0;
    if (firstCol === 0) for (i = 0; i < r; i++) matrix[i][0] = 0;
};
