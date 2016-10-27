/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool compare(int* sCnt, int* pCnt, int size) {
    for (int i = 0; i < size; i++) {
        if (sCnt[i] != pCnt[i]) return false;
    }
    return true;
}

int* findAnagrams(char* s, char* p, int* returnSize) {
    int sLen = strlen(s);
    int pLen = strlen(p);
    int* res = (int*) malloc(sLen * sizeof(int));
    *returnSize = 0;
    if (sLen < pLen) return res;
    int pCnt[26];
    int sCnt[26];
    memset(pCnt, 0, 26 * sizeof(int));
    memset(sCnt, 0, 26 * sizeof(int));
    for (int i = 0; i < pLen; i++) {
        pCnt[p[i] - 'a']++;
    }
    for (int i = 0; i < pLen; i++) {
        sCnt[s[i] - 'a']++;
    }
    if (true == compare(sCnt, pCnt, 26)) {
        res[*returnSize] = 0;
        *returnSize += 1;
    }
    for (int i = pLen; i < sLen; i++) {
        sCnt[s[i - pLen] - 'a']--;
        sCnt[s[i] - 'a']++;
        if (true == compare(sCnt, pCnt, 26)) {
            res[*returnSize] = i - pLen + 1;
            *returnSize += 1;
        }
    }
    return res;
}