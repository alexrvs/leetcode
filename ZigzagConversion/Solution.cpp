class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1)
            return s;
        int step = 2 * (nRows - 1);
        int length = s.size();
        int index = 0;
        for (int i = 0; i < nRows; i++) {
            for (int j = 0; ; j++) {
                if (i == 0 || i == nRows - 1) {
                    index = step*j + i;
                    if (index < length) {
                        s.push_back(s[index]);
                    }
                    else
                        break;
                } else {
                    index = step*j - i;
                    if (index > 0 && index < length) {
                        s.push_back(s[index]);
                    }
                    index = step*j + i;
                    if (index < length) {
                        s.push_back(s[index]);
                    }
                    else
                        break;
                }
            }
        }
        for (int i = 0; i < length; i++) {
            s[i] = s[length+i];
        }
        s.resize(length);
        return s;
    }
};
