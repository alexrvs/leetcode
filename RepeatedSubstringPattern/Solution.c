bool isSame(char* str, int pl, int s) {
    for (int i = 0; i < pl; i++) {
        if (str[i] != str[s + i]) return false;
    }
    return true;
}

bool repeatedSubstringPattern(char* str) {
    int size = strlen(str);
    for (int l = 1; l <= size / 2; l++) {
        if (size % l == 0) {
            bool repeated = true;
            for (int s = l; s < size; s += l) {
                if (false == isSame(str, l, s)) {
                    repeated = false;
                    break;
                }
            }
            if (true == repeated) return true;
        }
    }
    return false;
}