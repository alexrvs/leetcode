/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructRectangle(int area, int* returnSize) {
    *returnSize = 2;
    int* res = (int*) malloc((*returnSize) * sizeof(int));
    for (int i = area; i > 0; i--) {
        if (area % i == 0) {
            int w = i;
            int l = area / i;
            if (w <= l) {
                res[0] = l;
                res[1] = w;
                break;
            }
        }
    }
    return res;
}