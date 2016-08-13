int divide(int dividend, int divisor) {
    if (!divisor || (dividend == INT_MIN && divisor == -1))
        return INT_MAX;
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
    long long dvd = labs(dividend);
    long long dvs = labs(divisor);
    int res = 0;
    long temp = dvs;
    long mult = 1;
    while (dvd >= (temp << 1)) {
        temp <<= 1;
        mult <<= 1;
    }
    while (mult > 0) {
        if (dvd >= temp) {
            dvd -= temp;
            res += mult;
        } else {
            temp >>= 1;
            mult >>= 1;
        }
    }
    return sign == 1 ? res : -res;
}
