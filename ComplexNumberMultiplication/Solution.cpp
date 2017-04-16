class Solution {
private:
    vector<int> parseComplexNumber(string& str) {
        vector<int> complexNumber(2, 0);
        int size = str.size();
        int num = 0;
        int neg = 1;
        bool readNum = false;
        for (int i = 0; i < size; i++) {
            if (str[i] == '-' || str[i] == '+') {
                if (readNum == true) {
                    readNum = false;
                    complexNumber[0] = neg * num;
                    num = 0;
                    neg = 1;
                }
                if (str[i] == '-') neg = -1;
            }
            if (str[i] >= '0' && str[i] <= '9') {
                readNum = true;
                num = 10 * num + str[i] - '0';
            }
            if (i == size - 1) {
                if (str[i] == 'i') {
                    complexNumber[1] = neg * num;
                } else {
                    complexNumber[0] = neg * num;
                }
            }
        }
        return complexNumber;
    }

public:
    string complexNumberMultiply(string a, string b) {
        vector<int> numA = parseComplexNumber(a);
        vector<int> numB = parseComplexNumber(b);
        vector<int> resNum(2, 0);
        resNum[0] = numA[0] * numB[0] - numA[1] * numB[1];
        resNum[1] = numA[1] * numB[0] + numA[0] * numB[1];
        stringstream ss;
        ss << resNum[0] << "+" << resNum[1] << "i";
        return ss.str();
    }
};