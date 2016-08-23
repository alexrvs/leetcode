class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> cnt(26, 0);
        int size = s.size();
        for (int i = 0; i < size; i++) {
            cnt[s[i] - 'a']++;
        }
        for (int i = 0; i < size; i++) {
            if (cnt[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};
