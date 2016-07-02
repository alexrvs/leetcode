char* convertToTitle(int n) {
    int t = n;
    int c = 0;
    while (t > 0) {
        t = (--t) / 26;
        c++;
    }
    char* res = (char*) malloc((c+1) * sizeof(char));
    res[c] = 0;
    while (n > 0) {
        res[--c] =  'A' + (--n) % 26;
        n /= 26;
    }
    return res;
}
