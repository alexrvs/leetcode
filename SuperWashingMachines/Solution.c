int findMinMoves(int* machines, int machinesSize) {
    int size = machinesSize;
    int* sums = (int*) malloc((size + 1) * sizeof(int));
    sums[0] = 0;
    for (int i = 0; i < size; i++) {
         sums[i + 1] = sums[i] + machines[i];
    }
    if (sums[size] % size != 0) return -1;
    int avg = sums[size] / size;
    int res = 0;
    for (int i = 0; i < size; i++) {
        int l = avg * i - sums[i];
        int r = avg * (size - 1 - i) - (sums[size] - sums[i + 1]);
        if (l > 0 && r > 0) {
            if (res < l + r) res = l + r;
        } else {
            if (l < 0) l = -l;
            if (r < 0) r = -r;
            if (res < l) res = l;
            if (res < r) res = r;
        }
    }
    free(sums);
    return res;
}