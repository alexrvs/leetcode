class Solution {
public:
    vector<vector<int> > transTable;

    int inputType(char a) {
        if (a == ' ') return 0;
        else if (a == '+' || a == '-') return 1;
        else if (a >= '0' && a <= '9') return 2;
        else if (a == '.') return 3;
        else if (a == 'e') return 4;
        else return 5;
    }

    void initTransTable() {
        transTable.resize(9, vector<int>(5, -1));
        transTable[0][0] = 0;
        transTable[0][1] = 1;
        transTable[0][2] = 2;
        transTable[0][3] = 7;
        transTable[7][2] = 3;
        transTable[1][2] = 2;
        transTable[1][3] = 7;
        transTable[2][2] = 2;
        transTable[2][0] = 6;
        transTable[2][3] = 3;
        transTable[2][4] = 4;
        transTable[3][2] = 3;
        transTable[3][4] = 4;
        transTable[3][0] = 6;
        transTable[4][1] = 8;
        transTable[8][2] = 5;
        transTable[4][2] = 5;
        transTable[5][2] = 5;
        transTable[5][0] = 6;
        transTable[6][0] = 6;
    }

    bool isNumber(string s) {
        int size = s.size();
        if (size == 0) return false;
        initTransTable();
        int curState = 0;
        int i = 0;
        while (i < size) {
            int curInput = inputType(s[i]);
            if(curInput == 5) return false;
            curState = transTable[curState][curInput];
            if(curState == -1) return false;
            i++;
        }
        if (curState == 2 || curState == 3 || curState == 5 || curState == 6) return true;
        else return false;
    }
};
