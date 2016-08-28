bool canFinish(int numCourses, int** prerequisites, int prerequisitesRowSize, int prerequisitesColSize) {
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
            }
        }
        if (changed == false) break;
    }
    for (int i = 0; i < numCourses; i++) {
        if (out[i] > 0) return false;
    }
    free(in);
    free(out);
    free(depend);
    return true;
}
