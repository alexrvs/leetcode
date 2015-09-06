class Solution {
public:
    int hIndex(vector<int>& citations) {
        int hIndex = 0;
        int cnt = 0;
        int size = citations.size();
        for(int i = 0; i < size; i++) {
            cnt = size - i;
            if(citations[i] >= cnt) {
                if(hIndex < cnt) {
                    hIndex = cnt;
                }
            }
        }
        return hIndex;
    }
};
