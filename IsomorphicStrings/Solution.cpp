class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> m1;
        map<char, char> m2;
        int size = s.size();
        char cs, ct;
        for (int i = 0; i < size; i++) {
            cs = s[i];
            ct = t[i];
            if (0 != m1.count(cs)) {
                if (ct != m1[cs]) return false;
            } else {
                m1[cs] = ct;
            }
            if (0 != m2.count(ct)) {
                if (cs != m2[ct]) return false;
            } else {
                m2[ct] = cs;
            }
        }
        return true;
    }
};
