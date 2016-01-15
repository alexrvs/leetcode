class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target) {
                r = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            }
        }
        int left = l;
        l = 0;
        r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > target) {
                r = mid - 1;
            } else if (nums[mid] <= target) {
                l = mid + 1;
            }
        }
        int right = r;
        if(nums[left] != target || nums[right] != target) {
            left = right = -1;
        }
        vector<int> ans(2);
        ans[0] = left;
        ans[1] = right;
        return ans;
    }
};
