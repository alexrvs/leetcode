bool compareCharCnts(int* charCnts1, int* charCnts2) {
    for (int i = 0; i < 26; i++) {
        if (charCnts1[i] != charCnts2[i]) {
            return false;
        }
    }
    return true;
}

bool checkInclusion(char* s1, char* s2) {
    int s1Size = strlen(s1);
    int s2Size = strlen(s2);
    if (s2Size < s1Size) return false;
    int s1CharCnts[26];
    int s2CharCnts[26];
    memset(s1CharCnts, 0, 26 * sizeof(int));
    memset(s2CharCnts, 0, 26 * sizeof(int));
    for (int i = 0; i < s2Size; i++) {
        if (i < s1Size) {
            s1CharCnts[s1[i] - 'a']++;
        }
        s2CharCnts[s2[i] - 'a']++;
        if (i >= s1Size) {
            s2CharCnts[s2[i - s1Size] - 'a']--;
        }
        if (i >= s1Size - 1) {
            if (true == compareCharCnts(s1CharCnts, s2CharCnts)) {
                return true;
            }
        }
    }
    return false;
}