class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int length = 2 * s.size() + 2;

        char* ch = new char[length + 1];
        ch[0] = '*';
        for (int i = 0; i < s.size(); i++) {
            ch[2 * i + 1] = '#';
            ch[2 * i + 2] = s[i];
        }
        ch[length - 1] = '#';
        ch[length] = '\0';

        int* p = new int[length];
        memset(p, 0, sizeof(int) * length);

        int maxIdx = 0;
        int symmetric = 0, center = 0;
        for (int i = 1; i < length; i++) {
            if (symmetric > i) {
                p[i] = p[2 * center - i] < symmetric - i ? p[2 * center - i] : symmetric - i;
            }
            else {
                p[i] = 1;
            }
            while (ch[i + p[i]] == ch[i - p[i]]) {
                p[i]++;
            }
            if (i + p[i] > symmetric) {
                symmetric = i + p[i];
                center = i;
            }
            if (p[i] > p[maxIdx]) {
                maxIdx = i;
            }
        }
        int temp = p[maxIdx];

        delete ch;
        delete p;

        return s.substr((maxIdx >> 1) - (temp >> 1), temp - 1);
    }
};
