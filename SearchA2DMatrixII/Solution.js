var searchRow = function(row, target) {
    var l = 0;
    var r = row.length;
    while (l < r) {
        m = l + ((r - l) >> 1);
        if (row[m] < target) l = m + 1;
        else if (row[m] == target) return true;
        else r = m;
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
    while (l < r) {
        m = l + ((r - l) >> 1);
        if (matrix[m][0] <= target) l = m + 1;
        else r = m;
    }
    for (var i = l - 1; i >= 0; i--) {
        if (searchRow(matrix[i], target)) return true;
    }
    return false;
};
