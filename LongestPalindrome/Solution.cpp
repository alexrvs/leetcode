class Solution {
public:
    int longestPalindrome(string s) {
        int cnt[52];
        memset(cnt, 0, 52 * sizeof(int));
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                cnt[s[i] - 'a']++;
            } else if (s[i] >= 'A' && s[i] <= 'Z') {
                cnt[s[i] - 'A' + 26]++;
            }
        }
        int max = 0;
        int hasEven = 0;
        for (int i = 0; i < 52; i++) {
            if (cnt[i] % 2 != 0) hasEven = 1;
            max += (cnt[i] / 2) * 2;
        }
        return max + hasEven;
    }
};