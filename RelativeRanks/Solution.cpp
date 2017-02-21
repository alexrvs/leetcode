class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<pair<int, int>> numsIdx;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            numsIdx.push_back(pair<int, int>(nums[i], i));
        }
        sort(numsIdx.begin(), numsIdx.end());
        vector<string> res(size);
        for (int i = size - 1; i >= 0; i--) {
            if (i == size - 1) {
                res[numsIdx[i].second] = "Gold Medal";
            } else if (i == size - 2) {
                res[numsIdx[i].second] = "Silver Medal";
            } else if (i == size - 3) {
                res[numsIdx[i].second] = "Bronze Medal";
            } else {
                stringstream ss;
                ss << size - i;
                res[numsIdx[i].second] = ss.str();
            }
        }
        return res;
    }
};