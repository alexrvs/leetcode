class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        stringstream res;
        res << nums[0];
        int size = nums.size();
        for (int i = 1; i < size; i++) {
            if (i == 1 && size > 2) {
                res << "/(" << nums[i];
            } else {
                res << "/" << nums[i];
            }
        }
        if (size > 2) res << ")";
        return res.str();
    }
};