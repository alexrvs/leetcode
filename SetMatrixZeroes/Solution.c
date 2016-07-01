void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    int r = matrixRowSize;
    if (r == 0) return;
    int c = matrixColSize;
    int firstRow = 1;
    int firstCol = 1;
    for (int i = 0; i < r; i++) {
        if (matrix[i][0] == 0) firstCol = 0;
        for (int j = 0; j < c; j++) {
            if (i == 0 && matrix[i][j] == 0) firstRow = 0;
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < r; i++) {
        for (int j = 1; j < c; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
    if (firstRow == 0) {
        for (int j = 0; j < c; j++) matrix[0][j] = 0;
    }
    if (firstCol == 0) {
        for (int i = 0; i < r; i++) matrix[i][0] = 0;
    }
    return;
}
