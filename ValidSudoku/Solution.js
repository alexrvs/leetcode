/**
 *  * @param {character[][]} board
 *   * @return {boolean}
 *    */
var isValidSudoku = function(board) {
    var l = board.length;
    var rowNums = new Array(9);
    var colNums = new Array(9);
    var gridNums = new Array(9);
    for (var i = 0; i < l; i++) {
        for (var j = 0; j < l; j++) {
            var g = Math.floor(i / 3) * 3 + Math.floor(j / 3);
            if (board[i][j] != '.') {
                var num = Number(board[i][j]);
                var val = 1 << (Number(board[i][j]) - 1);
                if ((rowNums[i] & val) !== 0 || (colNums[j] & val) !== 0 || (gridNums[g] & val) !== 0) {
                    return false;
                } else {
                    rowNums[i] |= val;
                    colNums[j] |= val;
                    gridNums[g] |= val;
                }
            }
        }
    }
    return true;
};
