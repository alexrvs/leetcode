char* shortestPalindrome(char* s) {
    int size = strlen(s);
    if (size < 2) return s;
    int reslen = 2 * size + 1;
    char* res = (char*) malloc((reslen + 1) * sizeof(char));
    res[reslen] = 0;
    res[size] = '#';
    for (int i = 0; i < size; i++) {
        res[i] = s[i];
        res[reslen - 1 - i] = s[i];
    }
    int* table = (int*) malloc(reslen * sizeof(int));
    memset(table, 0, reslen * sizeof(int));
    int idx = 0;
    for (int i = 1; i < reslen; i++) {
        if (res[i] == res[idx]) {
            table[i] = ++idx;
        } else {
            idx = table[i - 1];
            while (idx > 0 && res[i] != res[idx]) {
                idx = table[idx - 1];
            }
            if (res[i] == res[idx]) idx++;
            table[i] = idx;
        }
    }
    idx = 0;
    for (int i = size - 1; i >= table[reslen - 1]; i--) {
        res[idx++] = s[i];
    }
    for (int i = 0; i < size; i++) {
        res[idx++] = s[i];
    }
    res[idx] = 0;
    free(table);
    return res;
}