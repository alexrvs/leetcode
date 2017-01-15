class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int size = nums.size();
        int max = 0;
        for (int i = 0; i < size; i++) {
            if (nums[i] == 0) cnt = 0;
            else {
                cnt++;
                if (max < cnt) max = cnt;
            }
        }
        return max;
    }
};