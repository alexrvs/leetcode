class Solution {
private:
    void helper(vector<string>& res, string str, int a, int b) {
        if (a == 0 && b == 0) {
            res.push_back(str);
        } else if (a == 0) {
            helper(res, str + ")", a, b - 1);
        } else {
            helper(res, str + "(", a - 1, b);
            if (a < b) {
                helper(res, str + ")", a, b - 1);
            }
        }
        return;
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str = "";
        helper(res, str, n, n);
        return res;
    }
};
