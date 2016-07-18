int hIndex(int* citations, int citationsSize) {
    int size = citationsSize;
    int* cnt = (int*) malloc((size + 1) * sizeof(int));
    memset(cnt, 0, (size + 1) * sizeof(int));
    for (int i = 0; i < size; i++) {
        if (citations[i] >= size) {
            cnt[size]++;
        } else {
            cnt[citations[i]]++;
        }
    }
    if (cnt[size] >= size) {
        return size;
    }
    for (int i = size - 1; i >= 0; i--) {
        cnt[i] += cnt[i+1];
        if (cnt[i] >= i) {
            free(cnt);
            return i;
        }
    }
    return 0;
}
