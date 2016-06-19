void loop(int** matrix, int si, int sj, int rl, int cl, int dir, int* result, int* rSize) {
        if (rl == 0 || cl == 0)
            return;
        int i;
        if (dir == 0) {
            for (i = sj; i < sj+cl; i++) {
                result[(*rSize)++] = matrix[si][i];
            }
            loop(matrix, si+1, i-1, rl-1, cl, 1, result, rSize);
        } else if (dir == 1) {
            for (i = si; i < si+rl; i++) {
                result[(*rSize)++] = matrix[i][sj];
            }
            loop(matrix, i-1, sj-1, rl, cl-1, 2, result, rSize);
        } else if (dir == 2) {
            for (i = sj; i > sj-cl; i--) {
                result[(*rSize)++] = matrix[si][i];
            }
            loop(matrix, si-1, i+1, rl-1, cl, 3, result, rSize);
        } else if (dir == 3) {
            for (i = si; i > si-rl; i--) {
                result[(*rSize)++] = matrix[i][sj];
            }
            loop(matrix, i+1, sj+1, rl, cl-1, 0, result, rSize);
        }
        return;
    }

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    int* res = (int*) malloc((matrixRowSize * matrixColSize) * sizeof(int));
    if (matrixRowSize == 0) return res;
    int rSize = 0;
    loop(matrix, 0, 0, matrixRowSize, matrixColSize, 0, res, &rSize);
    return res;
}
