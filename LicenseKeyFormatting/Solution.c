char* licenseKeyFormatting(char* S, int K) {
    int charNum = 0;
    int size = strlen(S);
    if (size == 0) return S;
    for (int i = 0; i < size; i++) {
        if (('a' <= S[i] && S[i] <= 'z') ||
            ('A' <= S[i] && S[i] <= 'Z') ||
            ('0' <= S[i] && S[i] <= '9')) charNum++;
    }
    if (charNum == 0) return "";
    int dashNum = charNum / K;
    if (charNum % K == 0) dashNum--;
    int resLen = dashNum + charNum;
    char* res = (char*) malloc((resLen + 1) * sizeof(char));
    res[resLen] = 0;
    int resIdx = resLen - 1;
    int cnt = 0;
    for (int i = size - 1; i >= 0 && resIdx >= 0; i--) {
        if ('a' <= S[i] && S[i] <= 'z') {
            res[resIdx] = S[i] - 'a' + 'A';
            resIdx--;
            cnt++;
        } else if (('A' <= S[i] && S[i] <= 'Z') ||
                   ('0' <= S[i] && S[i] <= '9')) {
            res[resIdx] = S[i];
            resIdx--;
            cnt++;
        }
        if (cnt == K && resIdx >= 0) {
            res[resIdx] = '-';
            resIdx--;
            cnt = 0;
        }
    }
    return res;
}