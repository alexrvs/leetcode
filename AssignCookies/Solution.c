static int comp(void* a, void* b) {
    return *((int*)a) - *((int*)b);
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    qsort(g, gSize, sizeof(int), comp);
    qsort(s, sSize, sizeof(int), comp);
    int gi = gSize - 1;
    int si = sSize - 1;
    int cnt = 0;
    while (gi >= 0 && si >= 0) {
        if (g[gi] <= s[si])  {
            cnt++;
            si--;
        }
        gi--;
    }
    return cnt;
}