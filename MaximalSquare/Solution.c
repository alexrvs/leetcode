int maximalSquare(char** matrix, int matrixRowSize, int matrixColSize) {
    if (matrixRowSize == 0 || matrixColSize == 0) return 0;
    int** dp = (int**) malloc((matrixRowSize + 1) * sizeof(int*));
    int max = 0;
    for (int i = 0; i <= matrixRowSize; i++) {
        dp[i] = (int*) malloc((matrixColSize + 1) * sizeof(int));
        memset(dp[i], 0, (matrixColSize + 1) * sizeof(int));
        for (int j = 1; j <= matrixColSize; j++) {
            if (i > 0 && matrix[i - 1][j - 1] == '1') {
                dp[i][j] = dp[i - 1][j - 1];
                if (dp[i][j - 1] < dp[i][j]) dp[i][j] = dp[i][j - 1];
                if (dp[i - 1][j] < dp[i][j]) dp[i][j] = dp[i - 1][j];
                dp[i][j]++;
                if (dp[i][j] > max) max = dp[i][j];
            }
        }
    }
    for (int i = 0; i <= matrixRowSize; i++) {
        free(dp[i]);
    }
    free(dp);
    return max * max;
}