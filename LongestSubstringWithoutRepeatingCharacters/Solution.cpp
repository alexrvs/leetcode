class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int start = 0;
            int len = 0;
            int max = 0;
            int i = 0;
            if (s.size() == 0)
                return 0;
            for (i = 1; i < s.size(); i++) {
                for (int j = start; j < i; j++) {
                    if ( s[j] == s[i] ) {
                        len = i - start;
                        if (max < len)
                            max = len;
                        start = j+1;
                        break;
                    }
                }
            }
            len = i - start;
            if (max < len)
                max = len;
            return max;
        }
};
