class Solution {
private:
    bool helper(vector<int> &sidesLength,const vector<int> &matches, int index, const int target) {
        if (index == matches.size())
            return sidesLength[0] == sidesLength[1] && sidesLength[1] == sidesLength[2] && sidesLength[2] == sidesLength[3];
        for (int i = 0; i < 4; i++) {
            if (sidesLength[i] + matches[index] > target) {
                continue;
            }
            int j = i;
            while (--j >= 0) {
                if (sidesLength[i] == sidesLength[j]) {
                    break;
                }
            }
            if (j != -1) continue;
            sidesLength[i] += matches[index];
            if (helper(sidesLength, matches, index + 1, target))
                return true;
            sidesLength[i] -= matches[index];
        }
        return false;
    }
    
    static int compare(int& a, int& b) {
        return a > b;
    }
    
public:
    bool makesquare(vector<int>& nums) {
        int size = nums.size();
        if (size < 4) return false;
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += nums[i];
        }
        if (sum % 4 != 0) return false;
        int l = sum / 4;
        sort(nums.begin(), nums.end(), compare);
        vector<int> sidesLength(4, 0);
        return helper(sidesLength, nums, 0, l);
    }
};