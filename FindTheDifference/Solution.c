char findTheDifference(char* s, char* t) {
    int cnt[26];
    memset(cnt, 0, 26 * sizeof(int));
    char* c = t;
    while (*c != 0) {
        cnt[*c - 'a']++;
        c++;
    }
    c = s;
    while (*c != 0) {
        cnt[*c - 'a']--;
        c++;
    }
    int i = 0;
    for (; i < 26; i++) {
        if (cnt[i] == 1) break;
    }
    return 'a' + i;
}
