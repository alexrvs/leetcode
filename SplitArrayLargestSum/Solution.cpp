class Solution {
private:
    bool valid(vector<int>& nums, long max, int m) {
        int cnt = 1;
        long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > max) {
                cnt++;
                sum = nums[i];
                if (cnt > m) return false;
            }
        }
        return true;
    }

    int search(vector<int>& nums, long start, long end, int m) {
        long mid = 0;
        while (start < end) {
            mid = start + (end - start) / 2;
            if (valid(nums, mid, m)) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return end;
    }
    
public:
    int splitArray(vector<int>& nums, int m) {
        long sum = 0;
        long max = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (max < nums[i]) max = nums[i];
        }
        return (int)search(nums, max, sum, m);
    }
};