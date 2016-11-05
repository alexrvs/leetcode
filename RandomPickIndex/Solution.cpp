class Solution {
private:
    vector<pair<int, int> > ordered;
    
    static bool compare(const pair<int, int>& pa, const pair<int, int>& pb) {
        if (pa.first < pb.first) return 1;
        return 0;
    }
    
public:
    Solution(vector<int> nums) {
        ordered.clear();
        for (int i = 0; i < nums.size(); i++) {
            ordered.push_back(pair<int, int>(nums[i], i));
        }
        sort(ordered.begin(), ordered.end());
        srand((unsigned)time(NULL));
    }
    
    int pick(int target) {
        vector<pair<int, int> >::iterator start_it = std::lower_bound(ordered.begin(), ordered.end(), pair<int, int>(target, 0), Solution::compare);
        vector<pair<int, int> >::iterator end_it = std::upper_bound(ordered.begin(), ordered.end(), pair<int, int>(target, 0), Solution::compare);
        int len = end_it - start_it;
        vector<pair<int, int> >::iterator it = start_it + (rand() % len);
        return it->second;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */