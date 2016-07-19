bool searchRow(int* row, int col, int target) {
    int size = col;
    int l = 0;
    int r = size;
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
    int size = matrixRowSize;
    int l = 0;
    int r = size;
    int m = 0;
    while (l < r) {
        m = l + (r - l) / 2;
        if (matrix[m][0] <= target) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    for (int i = l - 1; i >= 0; i--) {
        if (searchRow(matrix[i], matrixColSize, target) == true) {
            return true;
        }
    }
    return false;
}
