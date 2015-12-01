class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        int l = strs.size();
        if (l == 0) return res;
        if (l == 1) return strs[0];
        int l0 = strs[0].size();
        for (int idx = 0; idx < l0; idx++) {
            char c = strs[0][idx];
            for (int i = 1; i < l; i++) {
                if (idx >= strs[i].size() || c != strs[i][idx]) return res;
            }
            res += c;
        }
        return res;
    }
};
