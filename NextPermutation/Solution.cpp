class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int i, j;
        int len=num.size();
        for(i = len - 2; i >= 0; i--) {
            if(num[i] < num[i+1]) {
                for(j = len - 1; j > i - 1; j--) {
                    if(num[i] < num[j]) {
                        break;
                    }
                }
                swap(num[i], num[j]);
                reverse(num.begin() + i + 1, num.end());
                return;
            }
        }
        reverse(num.begin(), num.end());
        return;
    }
};
