class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> digits;
        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }
        if (digits.size() == 1) return -1;
        int i = 1;
        for (; i < digits.size(); i++) {
            if (digits[i] < digits[i - 1]) {
                break;
            }
        }
        if (i == digits.size()) return -1;
        int l = 0;
        int r = i - 1;
        int t = 0;
        while (l < r) {
            t = digits[l];
            digits[l] = digits[r];
            digits[r] = t;
            l++;
            r--;
        }
        for (int j = i - 1; j >= 0; j--) {
            if (digits[j] > digits[i]) {
                t = digits[i];
                digits[i] = digits[j];
                digits[j] = t;
                break;
            }
        }
        n = 0;
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (n > INT_MAX / 10) return -1;
            if (n == INT_MAX / 10 && digits[i] > INT_MAX % 10) return -1;
            n = 10 * n + digits[i];
            
        }
        return n;
    }
};