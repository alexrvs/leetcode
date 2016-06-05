int uniquePaths(int m, int n) {
    int* path = (int*) malloc(m * n * sizeof(int));
    for (int i = 0; i < m; i++) {
        path[i] = 1;
    }
    for (int j = 0; j < n; j++) {
        path[j * m] = 1;
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            path[i + j * m] = path[i - 1 + j * m] + path[i + (j - 1) * m];
        }
    }
    return path[m * n - 1];
}
