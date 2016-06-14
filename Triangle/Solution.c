int minimumTotal(int** triangle, int triangleRowSize, int *triangleColSizes) {
    if (triangleRowSize == 0) return 0;
    for (int i = 1; i < triangleRowSize; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) { triangle[i][j] += triangle[i - 1][j]; }
            else if (j == i) { triangle[i][j] += triangle[i - 1][j - 1]; }
            else { triangle[i][j] += triangle[i - 1][j] < triangle[i - 1][j - 1] ? triangle[i - 1][j] : triangle[i - 1][j - 1]; }
        }
    }
    for (int i = 1; i < triangleRowSize; i++) {
        if (triangle[triangleRowSize - 1][i] < triangle[triangleRowSize - 1][0]) {
            triangle[triangleRowSize - 1][0] = triangle[triangleRowSize - 1][i];
        }
    }
    return triangle[triangleRowSize - 1][0];
}
