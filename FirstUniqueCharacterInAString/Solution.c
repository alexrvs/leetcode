int firstUniqChar(char* s) {
    int cnt[26];
    int size = strlen(s);
    memset(cnt, 0, 26 * sizeof(int));
    for (int i = 0; i < size; i++) {
        cnt[s[i] - 'a']++;
    }
    for (int i = 0; i < size; i++) {
        if (cnt[s[i] - 'a'] == 1) return i;
    }
    return -1;
}
