class Solution {
public:
    int hIndex(vector<int>& citations) {
        int cnt = 0;
        int size = citations.size();
        for (int i = 0; i < size; i++) {
            cnt = size - i;
            if (citations[i] >= cnt) {
                return cnt;
            }
        }
        return 0;
    }
};
