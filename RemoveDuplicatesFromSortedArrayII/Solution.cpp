class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int nonDupIdx = 0;
        if (n <= 1)
            return n;
        bool metOnce = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[nonDupIdx]) {
                metOnce = false;
                nonDupIdx++;
                nums[nonDupIdx] = nums[i];
            } else if (metOnce == false){
                metOnce = true;
                nonDupIdx++;
                nums[nonDupIdx] = nums[i];
            }
        }
        return nonDupIdx + 1;
    }
};
