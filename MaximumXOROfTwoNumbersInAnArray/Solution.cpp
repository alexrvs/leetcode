class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        int mask = 0;
        int size = nums.size();
        for (int i = 31; i >= 0; i--) {
            mask = mask | (1 << i);
            set<int> numHighBits;
            for (int j = 0; j < size; j++) {
                numHighBits.insert(nums[j] & mask);
            }
            int curMax = res | (1 << i);
            for (int highBits : numHighBits) {
                if (numHighBits.find(curMax ^ highBits) != numHighBits.end()) {
                    res = curMax;
                    break;
                }
            }
        }
        return res;
    }
};