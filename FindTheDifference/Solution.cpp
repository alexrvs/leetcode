class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> cnt(26, 0);
        for (int i = 0; i < t.size(); i++) {
            cnt[t[i] - 'a']++;
        }
        for (int i = 0; i < s.size(); i++) {
            cnt[s[i] - 'a']--;
        }
        for (int i = 0; i < cnt.size(); i++) {
            if (cnt[i] == 1) return 'a' + i;
        }
        return 'a';
    }
};
