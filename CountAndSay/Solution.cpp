class Solution {
public:
    string tostring(int num) {
        string res = "";
        while(num) {
            int mod = num % 10;
            res = char('0' + mod) + res;
            num /= 10;
        }
        return res;
    }

    string countAndSay(int n) {
        if(n< 0) return NULL;
        string seq = "1";
        for(int i = 1; i < n; ++i) {
            string tmp = "";
            int count = 0;
            char current = seq[0];
            int index = 0;
            while (index < seq.length()) {
                if (seq[index] == current) {
                    count++;
                } else {
                    tmp += tostring(count) + current;
                    current = seq[index];
                    count = 1;
                }
                index++;
            }
            tmp += tostring(count) + current;
            seq = tmp;
        }
        return seq;
    }
};
