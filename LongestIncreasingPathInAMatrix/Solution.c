int findPath(int i, int j, int** matrix, int** pathLen, int row, int col, int pre) {
    if (i < 0 || i >= row || j < 0 || j >= col || matrix[i][j] >= pre) return 0;
    if (pathLen[i][j] == 0) {
        int len = 0;
        int max = 0;
        len = findPath(i - 1, j, matrix, pathLen, row, col, matrix[i][j]);
        max = max > len ? max : len;
        len = findPath(i + 1, j, matrix, pathLen, row, col, matrix[i][j]);
        max = max > len ? max : len;
        len = findPath(i, j - 1, matrix, pathLen, row, col, matrix[i][j]);
        max = max > len ? max : len;
        len = findPath(i, j + 1, matrix, pathLen, row, col, matrix[i][j]);
        max = max > len ? max : len;
        pathLen[i][j] = max + 1;
    }
    return pathLen[i][j];
}

int longestIncreasingPath(int** matrix, int matrixRowSize, int matrixColSize) {
    int m = matrixRowSize;
    if (m == 0) return 0;
    int n = matrixColSize;
    if (n == 0) return 0;
    int** pathLen = (int**) malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        pathLen[i] = (int*) malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            pathLen[i][j] = 0;
        }
    }
    int max = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int l = findPath(i, j, matrix, pathLen, m, n, matrix[i][j] + 1);
            max = l > max ? l : max;
        }
    }
    return max;
}
