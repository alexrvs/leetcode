class Solution {
private:
    int parseInt(string token) {
        int len = token.size();
        int num = 0;
        bool neg = false;
        for (int i = 0; i < len; i++) {
            if (token[i] == '-') {
                neg = true;
            } else if (token[i] >= '0' && token[i] <= '9') {
                num = num * 10 + (token[i] - '0');
            }
        }
        if (num == 0) return 0;
        return (neg == false ? num : -num);
    }
    
public:
    int evalRPN(vector<string>& tokens) {
        int tokensSize = tokens.size();
        vector<int> nums(tokensSize, 0);
        int numsSize = 0;
        for (int i = 0; i < tokensSize; i++) {
            int len = tokens[i].size();
            if (len == 1 && (tokens[i][0] < '0' || tokens[i][0] > '9') ) {
                switch (tokens[i][0]) {
                    case '+':
                        nums[numsSize - 2] = nums[numsSize - 2] + nums[numsSize - 1];
                        break;
                    case '-':
                        nums[numsSize - 2] = nums[numsSize - 2] - nums[numsSize - 1];
                        break;
                    case '*':
                        nums[numsSize - 2] = nums[numsSize - 2] * nums[numsSize - 1];
                        break;
                    case '/':
                        nums[numsSize - 2] = nums[numsSize - 2] / nums[numsSize - 1];
                        break;
                    default:
                        break;
                }
                numsSize--;
            } else {
                nums[numsSize] = parseInt(tokens[i]);
                numsSize++;
            }
        }
        int res = nums[0];
        return res;
    }
};