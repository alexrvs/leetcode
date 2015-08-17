class Solution {
public:
    int s_nums[26];
    int t_nums[26];
    bool isAnagram(string s, string t) {
        for (int i = 0; i < s.size(); i++) {
            s_nums[s[i]-'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            t_nums[t[i]-'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (s_nums[i] != t_nums[i]) {
                return false;
            }
        }
        return true;
    }
};
