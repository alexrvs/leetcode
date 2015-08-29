class Solution {
private:
    string getstring(const int n) {
        stringstream newstr;
        newstr << n;
        return newstr.str();
    }
public:
    vector<string> summaryRanges(vector<int>& nums) {
        string range;
        vector<string> ranges;
        int size = nums.size();
        if (size == 0) return ranges;
        int start = nums[0];
        for (int i = 1; i < size; i++) {
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
