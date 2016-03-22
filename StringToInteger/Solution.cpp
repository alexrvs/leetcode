class Solution {
public:
    int myAtoi(string str) {
        char* cstr = NULL;
        int size = str.size();
        cstr = (char *)malloc(size);
        memcpy(cstr, str.c_str(), size);
        if (size == 0)
            return 0;
        bool neg = false;
        bool read = false;
        int digit = 0;
        int sum = 0;
        int max = 2147483647;
        int min = -2147483648;
        int limit = max / 10;
        int bottom = -limit;
        for (int i = 0; i < size; i++) {
            if (*cstr == ' ')
                cstr++;
            else
                break;
        }
        while (*cstr != 0 ) {
            if (*cstr == '-') {
                if (read)
                    break;
                neg = true;
                read = true;
                cstr++;
                continue;
            }
            if (*cstr == '+') {
                if (read)
                    break;
                neg = false;
                read = true;
                cstr++;
                continue;
            }
            digit = *cstr - '0';
            if (digit >= 0 && digit <= 9) {
                if (!neg) {
                    if (sum < limit) {
                        sum = sum * 10 + digit;
                    } else if (sum == limit) {
                        if (digit < 8)
                            sum = sum * 10 + digit;
                        else
                            return max;
                    } else
                        return max;
                } else {
                    if (sum > bottom) {
                        sum = sum * 10 - digit;
                    } else if (sum == bottom) {
                        if (digit < 9)
                            sum = sum * 10 - digit;
                        else
                            return min;
                    } else
                        return min;
                }
            } else
                break;
            cstr++;
        }
        return sum;
    }
};
