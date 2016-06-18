bool isLive(int** board, int i, int j, int row, int col) {
    int cnt = 0;
    for (int r = -1; r <=1; r++) {
        for (int c = -1; c <= 1; c++) {
            if (r == 0 && c == 0) continue;
            if (i + r >= 0 && i + r < row &&
                j + c >= 0 && j + c < col && board[i + r][j + c] & 0x0001 > 0) {
                    cnt++;
                }
        }
    }
    if (cnt == 2 && board[i][j] == 1) return true;
    if (cnt == 3) return true;
    return false;
}

void gameOfLife(int** board, int boardRowSize, int boardColSize) {
    if (boardRowSize == 0) return;
    for (int i = 0; i < boardRowSize; i++) {
        for (int j = 0; j < boardColSize; j++) {
            if (isLive(board, i, j, boardRowSize, boardColSize)) {
                board[i][j] += 2;
            }
        }
    }
    for (int i = 0; i < boardRowSize; i++) {
        for (int j = 0; j < boardColSize; j++) {
            board[i][j] >>= 1;
        }
    }
    return;
}
