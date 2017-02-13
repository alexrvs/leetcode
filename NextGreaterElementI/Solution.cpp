class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> res(findNums.size(), 0);
        for (int i = 0; i < findNums.size(); i++) {
            bool find = false;
            bool findGreater = false;
            for (int j = 0; j < nums.size(); j++) {
                if (findNums[i] == nums[j]) find = true;
                if (find == true && findNums[i] < nums[j]) {
                    findGreater = true;
                    res[i] = nums[j];
                    break;
                }
            }
            if (findGreater == false) {
                res[i] = -1;
            }
        }
        return res;
    }
};