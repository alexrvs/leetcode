class Solution {
private:
    vector<vector<int> > result;

    void dfs(int n,int index, vector<int>& order, vector<int>& used, vector<int> &num) {
        if (index == n) {
            vector<int> t;
            for (int i = 0; i < n; i++) t.push_back(num[order[i]]);
            result.push_back(t);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (used[i] == 0) {
                used[i] = 1;
                order[index] = i;
                dfs(n, index + 1, order, used, num);
                used[i] = 0;
                while (i < n - 1 && num[i + 1] == num[i]) i++;
            }
        }
    }

public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        result.clear();
        sort(num.begin(), num.end());
        int n = num.size();
        vector<int> order(n, 0);
        vector<int> used(n, 0);
        dfs(n, 0, order, used, num);
        return result;
    }
};
