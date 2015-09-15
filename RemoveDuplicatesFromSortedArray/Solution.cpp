class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) return size;
        int len = 1;
        int last_value = nums[0];
        for (int i = 1; i < size; i++) {
            if (nums[i] != last_value) {
                last_value = nums[i];
                nums[len++] = nums[i];
            }
        }
        return len;
    }
};
