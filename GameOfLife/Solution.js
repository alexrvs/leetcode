var isLive = function(board, i, j, row, col) {
    var cnt = 0;
    var r = 0;
    var c = 0;
    for (r = -1; r <=1; r++) {
        for (c = -1; c <= 1; c++) {
            if (r === 0 && c === 0) continue;
            if (i + r >= 0 && i + r < row &&
                j + c >= 0 && j + c < col && board[i + r][j + c] & 0x0001 > 0) {
                    cnt++;
                }
        }
    }
    if (cnt == 2 && board[i][j] == 1) return true;
    if (cnt == 3) return true;
    return false;
};

/**
 * @param {number[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var gameOfLife = function(board) {
    var r = board.length;
    var i, j;
    if (r === 0) return;
    var c = board[0].length;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (isLive(board, i, j, r, c)) {
                board[i][j] += 2;
            }
        }
    }
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            board[i][j] >>= 1;
        }
    }
    return;
};
