class Solution {
public:
    int titleToNumber(string s) {
        int size = s.size();
        int sum = 0;
        for (int i = 0; i < size; i++ ) {
            sum = sum * 26 + (s[i] - 'A' + 1);
        }
        return sum;
    }
};
