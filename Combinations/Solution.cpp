class Solution {
private:
    void solve(int c,int n,int k,vector<vector<int> > & ret,vector<int> & had) {
        if (k <= 0 || c > n) {
            if (k == 0) {
                ret.push_back(had);
            }
            return;
        }
        had.push_back(c);
        solve(c + 1, n, k - 1, ret, had);
        had.pop_back();
        solve(c + 1, n, k, ret, had);
        return;
    }

public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ret;
        vector<int> had;
        solve(1, n, k, ret, had);
        return ret;
    }
};
