char* reverseWords(char* s) {
    int i = 0;
    int l = 0;
    int r = 0;
    char t = 0;
    int size = strlen(s);
    while (i < size) {
        if (s[i] == ' ') {
            r = i - 1;
            while (l < r) {
                t = s[l];
                s[l] = s[r];
                s[r] = t;
                l++;
                r--;
            }
            l = i + 1;
        }
        i++;
    }
    r = i - 1;
    while (l < r) {
        t = s[l];
        s[l] = s[r];
        s[r] = t;
        l++;
        r--;
    }
    return s;
}