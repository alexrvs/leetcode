/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findOrder(int numCourses, int** prerequisites, int prerequisitesRowSize, int prerequisitesColSize, int* returnSize) {
        int* in = (int*) malloc(numCourses * sizeof(int));
        memset(in, 0, numCourses * sizeof(int));
        int* out = (int*) malloc(numCourses * sizeof(int));
        memset(out, 0, numCourses * sizeof(int));
        bool** depend = (bool**) malloc(numCourses * sizeof(bool*));
        for (int i = 0; i < numCourses; i++) {
            depend[i] = (bool*) malloc(numCourses * sizeof(bool));
            memset(depend[i], 0, numCourses * sizeof(bool));
        }
        for (int i = 0; i < prerequisitesRowSize; i++) {
            int from = prerequisites[i][0];
            int to = prerequisites[i][1];
            if (depend[to][from] != true) {
                in[to]++;
                out[from]++;
                depend[to][from] = true;
            }
        }
        bool changed = false;
        int* res = (int*) malloc(numCourses * sizeof(int));
        memset(res, 0, numCourses * sizeof(int));
        int* used = (int*) malloc(numCourses * sizeof(int));
        memset(used, 0, numCourses * sizeof(int));
        *returnSize = 0;
        while (true) {
            changed = false;
            for (int i = 0; i < numCourses; i++) {
                if (out[i] == 0 && in[i] > 0) {
                    for (int j = 0; j < numCourses; j++) {
                        if (depend[i][j] == true) {
                            changed = true;
                            out[j]--;
                            in[i]--;
                            depend[i][j] = false;
                        }
                    }
                    res[*returnSize] = i;
                    (*returnSize)++;
                    used[i] = 1;
                }
            }
            if (changed == false) break;
        }
        for (int i = 0; i < numCourses; i++) {
            if (out[i] > 0) {
                *returnSize = 0;
                return res;
            }
            if (used[i] == 0) {
                res[*returnSize] = i;
                (*returnSize)++;
                used[i] = 1;
            }
        }
        free(in);
        free(out);
        free(depend);
        free(used);
        return res;
}
