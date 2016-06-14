/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes) {
    int** triangle = (int**) malloc(numRows * sizeof(int *));
    *columnSizes = (int*) malloc(numRows * sizeof(int));
    for (int i = 0; i < numRows; i++) {
        triangle[i] = (int*) malloc((i + 1) * sizeof(int));
        triangle[i][0] = 1;
        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
        triangle[i][i] = 1;
        (*columnSizes)[i] = i + 1;
    }
    return triangle;
}
