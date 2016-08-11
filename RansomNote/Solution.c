bool canConstruct(char* ransomNote, char* magazine) {
    int nums[26];
    for (int i = 0; i < 26; i++) {
        nums[i] = 0;
    }
    char *s = magazine;
    while (*s != '\0') {
        nums[*s - 'a']++;
        s++;
    }
    s = ransomNote;
    while (*s != '\0') {
        nums[*s - 'a']--;
        if (nums[*s - 'a'] < 0) return false;
        s++;
    }
    return true;
}
