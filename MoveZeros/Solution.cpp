class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cur = 0;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] != 0) {
                nums[cur++] = nums[i];
            }
        }
        for (; cur < size; cur++) {
            nums[cur] = 0;
        }
        return;
    }
};
