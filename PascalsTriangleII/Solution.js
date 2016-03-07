/**
 * @param {number} rowIndex
 * @return {number[]}
 */
var getRow = function(rowIndex) {
    var row = [];
    var i = 0;
    var j = 0;
    for (i = 0; i <= rowIndex; i++) {
        row.push(0);
    }
    row[0] = 1;
    for (i = 1; i <= rowIndex; i++) {
        for (j = i; j >= 1; j--) {
            row[j] += row[j - 1];
        }
    }
    return row;
};
