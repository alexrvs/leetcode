class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int r = wall.size();
        if (r == 0) return 0;
        int c = wall[0].size();
        if (c == 0) return 0;
        unordered_map<int, int> sumCnt;
        int max = 0;
        for (int i = 0; i < r; i++) {
            int sum = 0;
            for (int j = 0; j < wall[i].size() - 1; j++) {
                sum += wall[i][j];
                if (sumCnt.find(sum) == sumCnt.end()) {
                    sumCnt[sum] = 1;
                } else {
                    sumCnt[sum]++;
                }
                if (max < sumCnt[sum]) {
                    max = sumCnt[sum];
                }
            }
        }
        return r - max;
    }
};