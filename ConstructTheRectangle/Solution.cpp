class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> res;
        for (int i = area; i > 0; i--) {
            if (area % i == 0) {
                int w = i;
                int l = area / i;
                if (w <= l) {
                    res.push_back(l);
                    res.push_back(w);
                    break;
                }
            }
        }
        return res;
    }
};