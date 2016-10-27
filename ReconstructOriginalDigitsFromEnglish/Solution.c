char* originalDigits(char* s) {
    char *pres[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    int pair[10][2] = { { 'z', 0 }, { 'w', 2 }, { 'x', 6 }, { 'g', 8 }, { 's', 7 }, { 'v', 5 }, { 'f', 4 }, { 'r', 3 }, { 'o', 1 }, { 'i', 9 } };
    int size = strlen(s);
    int cnt[26];
    memset(cnt, 0, 26 * sizeof(int));
    for (int i = 0; i < size; i++) {
        cnt[s[i] - 'a']++;
    }
    int res[10];
    int resLen = 0;
    memset(res, 0, 10 * sizeof(int));
    for (int i = 0; i < 10; i++) {
        int c = cnt[pair[i][0] - 'a'];
        if (c != 0) {
            resLen += c;
            res[pair[i][1]] = c;
            int len = strlen(pres[pair[i][1]]);
            for (int j = 0; j < len; j++) {
                cnt[pres[pair[i][1]][j] - 'a'] -= c;
            }
        }
    }
    char* resString = (char*) malloc((resLen + 1) * sizeof(char));
    int idx = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < res[i]; j++) {
            resString[idx] = '0' + i;
            idx++;
        }
    }
    resString[resLen] = 0;
    return resString;
}