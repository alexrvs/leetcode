class Solution {
public:
    string addBinary(string a, string b) {
        int la = a.size();
        int lb = b.size();
        int l = la > lb ? la : lb;
        int* d = new int[l];
        int c = 0;
        for (int i = 0; i < l; i++) {
            int da = 0;
            int db = 0;
            d[i] = 0;
            if (la - 1 - i >= 0) da = a[la - 1 - i] - '0';
            if (lb - 1 - i >= 0) db = b[lb - 1 - i] - '0';
            d[i] = (da + db + c) % 2;
            c = (da + db + c) / 2;
        }
        stringstream stream;
        if (c == 1) stream << 1;
        for (int i = l - 1; i >= 0; i--) {
            stream << d[i];
        }
        return stream.str();
    }
};
