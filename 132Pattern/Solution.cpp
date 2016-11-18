class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int size = nums.size();
        stack<int> largers;
        int s3 = INT_MIN;
        for (int i = size - 1; i >= 0; i--) {
            if (nums[i] < s3) {
                return true;
            } else {
                while (0 != largers.size() && largers.top() < nums[i]) {
                    s3 = largers.top();
                    largers.pop();
                }
            }
            largers.push(nums[i]);
        }
        return false;
    }
};