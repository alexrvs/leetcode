class Solution {
private:
    char c[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
public:
    string toHex(int num) {
        if (num == 0) return "0";
        string res = "";
        unsigned int m = num;
        while (m != 0) {
            res = c[(m & 15)] + res;
            m = (m >> 4);
        }
        return res;
    }
};
