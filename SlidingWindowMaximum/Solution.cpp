class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        vector<int> can(k, 0);
        int first = 0;
        int last = -1;
        int size = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (size != 0 && can[first] < i - k + 1) {
                first = (first + 1) % k;
                size--;
            }
            while (size != 0 && nums[can[last]] < nums[i]) {
                last = (last + k - 1) % k;
                size--;
            }
            last = (last + 1) % k;
            can[last] = i;
            size++;
            if (i >= k - 1) {
                res.push_back(nums[can[first]]);
            }
        }
        return res;
    }
};
