class Solution {
public:
    vector<int> helper(string& input, int start, int end) {
        vector<int> left;
        vector<int> right;
        vector<int> res;
        int num = 0;
        bool isNum = true;
        for (int i = start; i <= end; i++) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                isNum = false;
                left = helper(input, start, i-1);
                right = helper(input, i+1, end);
                for (int j = 0; j < left.size(); j++) {
                    for (int k = 0; k < right.size(); k++) {
                        if (input[i] == '+') {
                            res.push_back(left[j]+right[k]);
                        } else if (input[i] == '-') {
                            res.push_back(left[j]-right[k]);
                        } else if (input[i] == '*') {
                            res.push_back(left[j]*right[k]);
                        }
                    }
                }
            } else {
                num = 10*num + (input[i]-'0');
            }
        }
        if (isNum) {
            res.push_back(num);
        }
        return res;
    }
    vector<int> diffWaysToCompute(string input) {
        return helper(input, 0, input.size() - 1);
    }
};
