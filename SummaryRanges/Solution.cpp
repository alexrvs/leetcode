class Solution {
private:
    string getstring(const int n) {
        stringstream newstr;
        newstr << n;
        return newstr.str();
    }
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int start = -1;
        start = nums[0];
        string range;
        vector<string> ranges;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] == nums[i-1] + 1) continue;
            if (start == nums[i-1]) {
                range = getstring(start);
            } else {
                range = getstring(start) + "->" + getstring(nums[i-1]);
            }
            ranges.push_back(range);
            start = nums[i];
        }
        if (nums[size-1] == start) {
            range = getstring(start);
        } else {
            range = getstring(start) + "->" + getstring(nums[size-1]);
        }
        ranges.push_back(range);
        return ranges;
    }
};
