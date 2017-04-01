/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(int** matrix, int matrixRowSize, int matrixColSize, int* returnSize) {
    if (matrixRowSize == 0 || matrixColSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    int dir = 1;
    int i = 0;
    int j = 0;
    int r = matrixRowSize;
    int c = matrixColSize;
    int* res = (int*) malloc((r * c) * sizeof(int));
    *returnSize = 0;
    while (i >= 0 && i < r && j >= 0 && j < c) {
        res[*returnSize] = matrix[i][j];
        *returnSize += 1;
        if (dir == 1) {
            if (j == c - 1) {
                i++;
                dir = -dir;
            } else if (i == 0) {
                j++;
                dir = -dir;
            } else {
                i--;
                j++;
            }
        } else {
            if (i == r - 1) {
                j++;
                dir = -dir;
            } else if (j == 0) {
                i++;
                dir = -dir;
            } else {
                i++;
                j--;
            }
        }
    }
    return res;
}