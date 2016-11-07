class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        int size = points.size();
        if (size < 2) return size;
        sort(points.begin(), points.end());
        int cnt = 1;
        int end = points[0].second;
        for (int i = 1; i < points.size(); i++) {
            if (end > points[i].second) end = points[i].second;
            else if (end < points[i].first) {
                end = points[i].second;
                cnt++;
            }
        }
        return cnt;
    }
};