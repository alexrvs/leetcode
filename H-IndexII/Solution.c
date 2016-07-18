int hIndex(int* citations, int citationsSize) {
    int cnt = 0;
    int size = citationsSize;
    for (int i = 0; i < size; i++) {
        cnt = size - i;
        if (citations[i] >= cnt) {
            return cnt;
        }
    }
    return 0;
}
