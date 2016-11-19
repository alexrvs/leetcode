class Solution {
private:
    void helper(string s, int start, int segCnt, vector<int>& ipSegs, vector<string>& res) {
        if (segCnt == 0 && ipSegs.size() == 4) {
            ostringstream ip;
            for (int i = 0; i < ipSegs.size() - 1; i++) {
                ip << ipSegs[i] << ".";
            }
            ip << ipSegs[3];
            res.push_back(ip.str());
            return;
        }
        int num = 0;
        int rem = 0;
        int size = s.size();
        segCnt--;
        for (int i = 0; i < 3 && start + i < size; i++) {
            if (i > 0 && num == 0) break;
            num = num * 10 + s[start + i] - '0';
            rem = size - start - i - 1;
            if (rem >= 1 * segCnt && rem <= 3 * segCnt && num >= 0 && num < 256) {
                ipSegs.push_back(num);
                helper(s, start + i + 1, segCnt, ipSegs, res);
                ipSegs.pop_back();
            }
        }
        return;
    }
    
public:
    vector<string> restoreIpAddresses(string s) {
        int segCnt = 4;
        vector<int> ipSegs;
        vector<string> res;
        helper(s, 0, segCnt, ipSegs, res);
        return res;
    }
};