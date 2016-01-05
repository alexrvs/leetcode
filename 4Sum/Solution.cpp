class Solution {
public:
    void helper(vector<int>& num, int target, int firstIdx, int secondIdx, vector<vector<int> >& allPath) {
        int left = secondIdx + 1;
        int right = num.size() - 1;
        target = target-num[firstIdx]-num[secondIdx];
        while (left < right) {
            int sum = num[left]+num[right];
            if (sum < target) {
                left++;
            } else if (sum > target) {
                right--;
            } else {
                vector<int> path(4);
                path[0] = num[firstIdx];
                path[1] = num[secondIdx];
                path[2] = num[left];
                path[3] = num[right];
                allPath.push_back(path);
                left++;
            }
        }
    }

    vector<vector<int> > fourSum(vector<int> &num, int target) {
        int size = num.size();
        vector<vector<int> > paths;
        vector<vector<int> > res;

        sort(num.begin(), num.end());
        for(int i = 0; i < size - 3; i++) {
            for(int j = i+1; j < size - 2; j++) {
                helper(num, target, i, j, paths);
            }
        }

        for(int i = 0; i < paths.size(); i++) {
            if(find(res.begin(), res.end(), paths[i]) == res.end()) {
                res.push_back(paths[i]);
            }
        }

        return res;
    }
};
