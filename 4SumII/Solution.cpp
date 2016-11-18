class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> sumMap;
        int size = A.size();
        int sum = 0;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                sum = A[i] + B[j];
                sumMap[sum]++;
            }
        }
        int cnt = 0;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                sum = C[i] + D[j];
                cnt += sumMap[-sum];
            }
        }
        return cnt;
    }
};