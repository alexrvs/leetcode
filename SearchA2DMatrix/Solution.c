int search(int** matrix, int row, int target) {
    int l = 0;
    int r = row;
    int m = 0;
    while (l < r) {
        m = l + (r - l) / 2;
        if (matrix[m][0] <= target) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return r - 1;
}

bool searchRow(int* row, int col, int target) {
    int l = 0;
    int r = col;
    int m = 0;
    while (l < r) {
        m = l + (r - l) / 2;
        if (row[m] < target) {
            l = m + 1;
        } else if (row[m] == target) {
            return true;
        } else {
            r = m;
        }
    }
    return false;
}

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    if (matrixRowSize == 0) return false;
    int i = search(matrix, matrixRowSize, target);
    if (i < 0) return false;
    return searchRow(matrix[i], matrixColSize, target);
}
