int countSegments(char* s) {
    int size = strlen(s);
    int hasChar = 0;
    int cnt = 0;
    for (int i = 0; i < size; i++) {
        if (s[i] != ' ' && s[i] != '\n') {
            hasChar = 1;
        } else {
            if (hasChar == 1) {
                hasChar = 0;
                cnt++;
            }
        }
    }
    if (hasChar == 1) cnt++;
    return cnt;
}