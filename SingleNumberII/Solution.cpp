class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int count[32] = {0};
        int result = 0;
        int size = nums.size();
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < size; j++) {
                if ((nums[j] >> i) & 1) {
                    count[i]++;
                }
            }
            result |= ((count[i] % 3) << i);
        }
        return result;
    }
};