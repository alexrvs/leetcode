/**
 * @param {number} numRows
 * @return {number[][]}
 */
var generate = function(numRows) {
    var res = [];
    for (var i = 0; i < numRows; i++) {
        var row = [];
        row.push(1);
        for (var j = 1; j < i; j++) {
            row.push(res[i-1][j-1] + res[i-1][j]);
        }
        if (i > 0) row.push(1);
        res.push(row);
    }
    return res;
};
