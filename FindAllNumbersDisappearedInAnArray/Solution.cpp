class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            while (nums[i] != i + 1) {
                int temp = nums[i];
                if (nums[temp - 1] == temp) break;
                nums[i] = nums[temp - 1];
                nums[temp - 1] = temp;
            }
        }
        vector<int> res;
        for (int i = 0; i < size; i++) {
            if (nums[i] != i + 1) res.push_back(i + 1);
        }
        return res;
    }
};