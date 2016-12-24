/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int gMax = 0;
        int size = points.size();
        unordered_map<double, int> slopeCnt;
        for (int i = 0; i < size; i++) {
            int curMax = 0;
            int same = 0;
            slopeCnt.clear();
            int verticalCnt = 0;
            for (int j = i; j < size; j++) {
                if (points[i].x == points[j].x &&
                    points[i].y == points[j].y) {
                    same++;
                    continue;
                }
                
                if (points[i].x == points[j].x) {
                    verticalCnt++;
                    if (curMax < verticalCnt) curMax = verticalCnt;
                } else {
                    double slope = (double)(points[j].y - points[i].y)/(double)(points[j].x - points[i].x);
                    slopeCnt[slope]++;
                    if (curMax < slopeCnt[slope]) curMax = slopeCnt[slope];
                }
            }
            
            curMax += same;
            if (gMax < curMax) gMax = curMax;
        }
        return gMax;
    }
};