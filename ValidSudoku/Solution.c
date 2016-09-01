bool** initBoolMatrix(int r, int c) {
    bool** m = (bool**) malloc(r * sizeof(bool*));
    for (int i = 0; i < r; i++) {
        m[i] = (bool*) malloc(c * sizeof(bool));
        memset(m[i], 0, c * sizeof(bool));
    }
    return m;
}

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    bool** rowNums = initBoolMatrix(9, 9);
    bool** colNums = initBoolMatrix(9, 9);
    bool** gridNums = initBoolMatrix(9, 9);

    int size = boardRowSize;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int gridIdx = (i/3)*3+j/3;
            if (board[i][j] != '.') {
                int val = board[i][j] - '1';
                if (rowNums[i][val] || colNums[j][val] || gridNums[gridIdx][val]) {
                    free(rowNums);
                    free(colNums);
                    free(gridNums);
                    return false;
                } else {
                    rowNums[i][val] = true;
                    colNums[j][val] = true;
                    gridNums[gridIdx][val] = true;
                }
            }
        }
    }
    free(rowNums);
    free(colNums);
    free(gridNums);
    return true;
}
