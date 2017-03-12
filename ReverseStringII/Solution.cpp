class Solution {
public:
    string reverseStr(string s, int k) {
        int size = s.size();
        for (int i = 0; i < size; i += 2 * k) {
            int l = i;
            int r = l + k - 1;
            if (r >= size) r = size - 1;
            while (l < r) {
                char tmp = s[l];
                s[l] = s[r];
                s[r] = tmp;
                l++;
                r--;
            }
        }
        return s;
    }
};