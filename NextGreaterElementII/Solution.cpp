class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size = nums.size();
        vector<int> res(size, -1);
        for (int i = 0; i < size; i++) {
            for (int j = 1; j < size; j++) {
                int idx = (i + j) % size;
                if (nums[i] < nums[idx]) {
                    res[i] = nums[idx];
                    break;
                }
            }
        }
        return res;
    }
};