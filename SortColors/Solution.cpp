class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnts[3] = {0, 0, 0};
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            cnts[nums[i]]++;
        }
        int idx = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < cnts[i]; j++) {
                nums[idx++] = i;
            }
        }
        return;
    }
};
