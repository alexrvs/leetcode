class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int, int> map;
        map[0] = 0;
        vector<int> diff(size + 1, 0);
        int max = 0;
        for (int i = 1; i <= size; i++) {
            diff[i] = diff[i - 1] + (nums[i - 1] ? 1 : -1);
            if (map.find(diff[i]) != map.end()) {
                int l = i - map[diff[i]];
                if (max < l) {
                    max = l;
                }
            } else {
                map[diff[i]] = i;
            }
        }
        return max;
    }
};