class Solution {
private:
    void helper(vector<int>& nums, int index, vector<vector<int>>& res) {
        if (index == nums.size()) {
            return;
        }
        if (index == 0 || nums[index] != nums[index - 1]) {
            int n = res.size();
            res.push_back(vector<int>(1, nums[index]));
            for (int i = 1; i < n; i++) {
                vector<int> tmp = res[i];
                tmp.push_back(nums[index]);
                res.push_back(tmp);
            }
        } else {
            int n = res.size();
            int count = 0;
            for (int i = index; i >= 0; i--) {
                if (nums[i] == nums[index]) {
                    count++;
                } else {
                    break;
                }
            }
            for (int i = 1; i < n; i++) {
                int c = 0;
                for (int j = res[i].size() - 1; j >= 0; j--) {
                    if (res[i][j] == nums[index]) {
                        c++;
                    } else {
                        break;
                    }
                }
                if (c == count - 1) {
                    vector<int> tmp = res[i];
                    tmp.push_back(nums[index]);
                    res.push_back(tmp);
                }
            }
        }
        helper(nums, index+1, res);
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res(1, vector<int>());
        sort(nums.begin(), nums.end());
        helper(nums, 0, res);
        return res;
    }
};