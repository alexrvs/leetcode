bool isInterleave(char* s1, char* s2, char* s3) {
    int size1 = strlen(s1);
    int size2 = strlen(s2);
    int size3 = strlen(s3);
    if (size1 + size2 != size3) return false;
    bool** dp = (int **) malloc((size1 + 1) * sizeof(bool*));
    for (int i = 0; i <= size1; i++) {
        dp[i] = (int*) malloc((size2 + 1) * sizeof(bool));
        memset(dp[i], 0, (size2 + 1) * sizeof(bool));
        for (int j = 0; j <= size2; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = true;
            } else if (i == 0) {
                dp[i][j] = (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            } else if (j == 0) {
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
            } else {
                dp[i][j] = ((dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]) || (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]));
            }
        }
    }
    bool res = dp[size1][size2];
    for (int i = 0; i <= size1; i++) {
        free(dp[i]);
    }
    free(dp);
    return res;
}