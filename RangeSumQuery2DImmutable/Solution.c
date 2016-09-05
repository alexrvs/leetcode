struct NumMatrix {
    int** sum;
    int row;
    int col;
};

/** Initialize your data structure here. */
struct NumMatrix* NumMatrixCreate(int** matrix, int matrixRowSize, int matrixColSize) {
    struct NumMatrix* numMatrix = (struct NumMatrix*) malloc(sizeof(struct NumMatrix));
    numMatrix->row = matrixRowSize;
    numMatrix->col = matrixColSize;
    if (numMatrix->row == 0 || numMatrix->col == 0) {
        numMatrix->sum = NULL;
    } else {
        int** sum = (int**) malloc(matrixRowSize * sizeof(int*));
        for (int r = 0; r < matrixRowSize; r++) {
            sum[r] = (int*) malloc(matrixColSize * sizeof(int));
            for (int c = 0; c < matrixColSize; c++) {
                if (r == 0 && c == 0) sum[r][c] = matrix[r][c];
                else if (r == 0) sum[r][c] = sum[r][c - 1] + matrix[r][c];
                else if (c == 0) sum[r][c] = sum[r - 1][c] + matrix[r][c];
                else sum[r][c] = sum[r][c - 1] + sum[r - 1][c] - sum[r - 1][c - 1] + matrix[r][c];
            }
        }
        numMatrix->sum = sum;
    }
    return numMatrix;
}

int sumRegion(struct NumMatrix* numMatrix, int row1, int col1, int row2, int col2) {
    int row = numMatrix->row;
    int col = numMatrix->col;
    int** sum = numMatrix->sum;
    if (row1 >= row || row2 >= row || col1 >= col || col2 >= col) return 0;
    if (row1 == 0 && col1 == 0) return sum[row2][col2];
    else if (row1 == 0) return sum[row2][col2] - sum[row2][col1 - 1];
    else if (col1 == 0) return sum[row2][col2] - sum[row1 - 1][col2];
    else return sum[row2][col2] + sum[row1 - 1][col1 - 1] - sum[row2][col1 - 1] -sum[row1 - 1][col2];
}

/** Deallocates memory previously allocated for the data structure. */
void NumMatrixFree(struct NumMatrix* numMatrix) {
    free(numMatrix->sum);
    free(numMatrix);
}

// Your NumMatrix object will be instantiated and called as such:
// struct NumMatrix* numMatrix = NumMatrixCreate(matrix, matrixRowSize, matrixColSize);
// sumRegion(numMatrix, 0, 1, 2, 3);
// sumRegion(numMatrix, 1, 2, 3, 4);
// NumMatrixFree(numMatrix);
