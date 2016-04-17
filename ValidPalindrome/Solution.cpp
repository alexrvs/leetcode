class Solution {
private:
    char toOrd(char c) {
        int ord = c - '0';
        if (0 <= ord && ord <= 9) return c;
        ord = c - 'a';
        if (0 <= ord && ord <= 26) return c;
        ord = c - 'A';
        if (0 <= ord && ord <= 26) return 'a' + ord;
        return '+';
    }
public:
    bool isPalindrome(string s) {
        int size = s.size();
        int l = 0;
        int r = size - 1;
        while (l < r) {
            char lo = toOrd(s[l]);
            if (lo == '+') {
                l++;
                continue;
            }
            char ro = toOrd(s[r]);
            if (ro == '+') {
                r--;
                continue;
            }
            if (lo != ro) return false;
            l++;
            r--;
        }
        return true;
    }
};
