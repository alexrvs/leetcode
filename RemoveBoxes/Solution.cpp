class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int size = boxes.size();
        unordered_map<int, int> dp;
        return dfs(boxes, dp, size, 0, size - 1, 0);
    }

    int dfs(vector<int>& boxes, unordered_map<int, int>& dp, int n, int l, int r, int k) {
        if (l > r) return 0;
        int key = (l * n + r) * n + k;
        if (dp.find(key) != dp.end()) {
            return dp[key];
        }
        
        while (l < r && boxes[r - 1] == boxes[r]) {
            r--;
            k++;
        }
        
        while (l < r && boxes[l] == boxes[r]) {
            l++;
            k++;
        }
        
        key = (l * n + r) * n + k;
        dp[key] = dfs(boxes, dp, n, l, r - 1, 0) + (k + 1) * (k + 1);
        for (int i = l; i < r; i++) {
            if (boxes[i] == boxes[r]) {
                dp[key] = max(dp[key], dfs(boxes, dp, n, l, i, k + 1) + dfs(boxes, dp, n, i + 1, r - 1, 0));
            }
        }
        
        return dp[key];
    }
};