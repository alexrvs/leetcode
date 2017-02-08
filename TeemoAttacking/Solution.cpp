class Solution {
public:
    int fndPoisonedDuration(vector<int>& timeSeries, int duration) {
        int size = timeSeries.size();
        if (size == 0) return 0;
        int res = duration;
        for (int i = 1; i < size; i++) {
            int diff = timeSeries[i] - timeSeries[i - 1];
            if (diff > duration) {
                res += duration;
            } else {
                res += diff;
            }
        }
        return res;
    }
};