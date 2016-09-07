bool isSubsequence(char* s, char* t) {
    int sLen = strlen(s);
    int tLen = strlen(t);
    if (sLen == 0) return true;
    int idx = 0;
    for (int i = 0; i < tLen; i++) {
        if (t[i] == s[idx]) {
            idx++;
            if (idx == sLen) {
                return true;
            }
        }
    }
    return false;
}
