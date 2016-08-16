class Solution {
private:
    void dfs(vector<vector<int> >& res, vector<int>::iterator iter, vector<int>::iterator end, vector<int>& set) {
        if (iter == end) {
            res.push_back(set);
            return;
        }
        vector<int>::iterator temp = iter++;
        dfs(res, iter, end, set);
        set.push_back(*temp);
        dfs(res, iter, end, set);
        set.pop_back();
        return;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> set;
        dfs(res, nums.begin(), nums.end(), set);
        return res;
    }
};
