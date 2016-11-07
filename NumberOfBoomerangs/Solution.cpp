class Solution {
private:
    int distance(vector<pair<int, int>>& points, int i, int j) {
        int a = points[i].first - points[j].first;
        int b = points[i].second - points[j].second;
        return a * a + b * b;
    }
    
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int cnt = 0;
        int size = points.size();
        unordered_map<long, int> disMap;
        for (int i = 0; i < size; i++) {
            disMap.clear();
            for (int j = 0; j < size; j++) {
                if (i != j) {
                    int d = distance(points, i, j);
                    disMap[d]++;
                }
            }
            for (auto dis : disMap) {
                if (dis.second > 1) {
                    cnt += dis.second * (dis.second - 1);
                }
            }
        }
        return cnt;
    }
};