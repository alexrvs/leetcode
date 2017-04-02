void markVisit(int** M, int r, int c, int m, int* visit) {
    visit[m] = 1;
    for (int i = 0; i < c; i++) {
        if (1 == M[m][i] && 0 == visit[i]) {
            markVisit(M, r, c, i, visit);
        }
    }
    return;
}

int findCircleNum(int** M, int MRowSize, int MColSize) {
    int r = MRowSize;
    int res = 0;
    int* visit = (int*) malloc(r * sizeof(int));
    memset(visit, 0, r * sizeof(int));
    for (int i = 0; i < r; i++) {
        if (0 == visit[i]) {
            res++;
            markVisit(M, MRowSize, MColSize, i, visit);
        }
    }
    free(visit);
    return res;
}