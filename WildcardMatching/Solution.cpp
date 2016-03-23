class Solution {
public:
    bool isMatch(string s, string p) {
        int len1 = s.size();
        int len2 = p.size();
        bool star = false;
        int i = 0;
        int j = 0;
        int starIdx = 0;
        int saveIdx = 0;
        while (i < len1) {
            if (p[j] == '?') {
                i++;
                j++;
            } else if (p[j] == '*') {
                while (p[j] == '*') {
                    j++;
                }
                starIdx = j - 1;
                saveIdx = i;
                star = true;
            } else {
                if (s[i] == p[j]) {
                    i++;
                    j++;
                } else {
                    if (star == true) {
                        i = ++saveIdx;
                        j = starIdx + 1;
                    } else {
                        return false;
                    }
                }

            }
        }
        while (p[j] == '*') {
            j++;
        }
        return (i == len1 && j == len2);
    }
};
