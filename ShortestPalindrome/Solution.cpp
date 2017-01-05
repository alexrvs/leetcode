class Solution {
public:
    string shortestPalindrome(string s) {
        int size = s.size();
        if (size < 2) return s;
        string longstr = s + '-';
        for (int i = size - 1; i >= 0; i--) {
            longstr += s[i];
        }
        vector<int> table(2 * size + 1, 0);
        int idx = 0;
        for (int i = 1; i < 2 * size + 1; i++) {
            if (longstr[idx] == longstr[i]) {
                table[i] = table[i - 1] + 1;
                idx++;
            } else {
                idx = table[i - 1];
                while (idx > 0 && longstr[idx] != longstr[i]) {
                    idx = table[idx - 1];
                }
                if (longstr[idx] == longstr[i]) {
                    idx++;
                }
                table[i] = idx;
            }
        }
        int pl = table[2 * size];
        string res = "";
        for (int i = size - 1; i >= pl; i--) {
            res += s[i];
        }
        return res + s;
    }
};