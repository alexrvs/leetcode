var isValid = function(board, a, b) {
    var r = board.length;
    if (r === 0) return false;
    var c = board[0].length;
    var i = 0;
    var j = 0;
    for (i = 0; i < r; i++) {
        if (i != a && board[i][b] == board[a][b]) return false;
    }
    for (j = 0; j < c; j++) {
        if (j != b && board[a][j] == board[a][b]) return false;
    }
    var x = Math.floor(a / 3) * 3;
    var y = Math.floor(b / 3) * 3;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (x + i != a && y + j != b && board[x + i][y + j] == board[a][b]) {
                return false;
            }
        }
    }
    return true;
};

var dfs = function(board) {
    var r = board.length;
    if (r === 0) return false;
    var c = board[0].length;
    for (var i = 0; i < r; i++) {
        for (var j = 0; j < c; j++) {
            if (board[i][j] === 0) {
                for (var k = 1; k <= 9; k++) {
                    board[i][j] = k;
                    if (isValid(board, i, j) && dfs(board)) {
                        return true ;
                    }
                    board[i][j] = 0;
                }
                return false;
            }
        }
    }
    return true;
};

/**
 *  * @param {character[][]} board
 *   * @return {void} Do not return anything, modify board in-place instead.
 *    */
var solveSudoku = function(board) {
    var digits = [];
    var i = 0;
    var j = 0;
    for (i = 0; i < board.length; i++) {
        digits.push([]);
        for (j = 0; j < board[i].length; j++) {
            if (board[i][j] == '.') {
                digits[i].push(0);
            } else {
                digits[i].push(Number(board[i][j]));
            }
        }
    }
    dfs(digits);
    for (i = 0; i < digits.length; i++) {
        for (j = 0; j < digits[i].length; j++) {
            board[i][j] = String(digits[i][j]);
        }
    }
};
