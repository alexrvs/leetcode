int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    int r = obstacleGridRowSize;
    int c = obstacleGridColSize;
    if (obstacleGrid[0][0] == 1) return 0;
    obstacleGrid[0][0] = 1;
    for (int i = 1; i < r; i++) {
        if (obstacleGrid[i][0] == 1) obstacleGrid[i][0] = 0;
        else obstacleGrid[i][0] = obstacleGrid[i - 1][0];
    }
    for (int j = 1; j < c; j++) {
        if (obstacleGrid[0][j] == 1) obstacleGrid[0][j] = 0;
        else obstacleGrid[0][j] = obstacleGrid[0][j - 1];
    }
    for (int i = 1; i < r; i++) {
        for (int j = 1; j < c; j++) {
            if (obstacleGrid[i][j] == 1) obstacleGrid[i][j] = 0;
            else obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
        }
    }
    return obstacleGrid[r - 1][c - 1];
}
