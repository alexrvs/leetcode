class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int size = digits.size();
        int one = 1;
        int sum = 0;
        while (one == 1 && size > 0) {
            sum = digits[size-1] + one;
            one = sum/10;
            digits[size-1] = sum%10;
            size--;
        }
        if (one == 1) {
            vector<int> newDigits;
            newDigits.push_back(one);
            for (int i = 0; i < digits.size(); i++)
                newDigits.push_back(digits[i]);
            return newDigits;
        }
        return digits;
    }
};
