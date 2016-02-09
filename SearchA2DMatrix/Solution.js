var searchRow = function(row, target) {
    var l = 0;
    var r = row.length;
    var m = 0;
    while (l < r) {
        m = l + Math.floor((r - l) / 2 );
        if (row[m] < target) {
            l = m + 1;
        } else if (row[m] == target) {
            return true;
        } else {
            r = m;
        }
    }
    return false;
};

/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
    var l = 0;
    var r = matrix.length;
    var m = 0;
    while (l < r) {
        m = l + Math.floor((r - l) / 2);
        if (matrix[m][0] <= target) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    if (l === 0) return false;
    return searchRow(matrix[l - 1], target);
};
