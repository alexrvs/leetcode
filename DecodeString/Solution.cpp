class Solution {
public:
    string decodeString(string s) {
        int size = s.size();
        int prev = -1;
        string res = "";
        int num = 0;
        int n = 0;
        for (int i = 0; i < size; i++) {
            if (s[i] == '[') {
                n++;
                if (prev == -1) prev = i + 1;
            } else if (s[i] == ']') {
                n--;
                if (n == 0) {
                    string sub = decodeString(s.substr(prev, i - prev));
                    while (num > 0) {
                        res += sub;
                        num--;
                    }
                    prev = -1;
                }
            } else if (s[i] >= '0' && s[i] <= '9') {
                if (n == 0) num = 10 * num + s[i] - '0';
            } else {
                if (n == 0) res += s[i];
            }
        }
        return res;
    }
};
