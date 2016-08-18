int minDistance(char* word1, char* word2) {
    int l1 = strlen(word1);
    int l2 = strlen(word2);
    int* dp = (int*) malloc((l2 + 1) * sizeof(int));
    for (int i = 1; i <= l2; i++) {
        dp[i] = i;
    }
    int prev = 0;
    int cur = 0;
    for (int i = 0; i < l1; i++) {
        prev = i + 1;
        for (int j = 0; j < l2; j++) {
            if (word1[i] == word2[j]) {
                cur = dp[j];
            } else {
                cur = dp[j] < prev ? dp[j] : prev;
                cur = cur < dp[j + 1] ? cur : dp[j + 1];
                cur++;
            }
            dp[j] = prev;
            prev = cur;
        }
        dp[l2] = prev;
    }
    return dp[l2];
}
