#define my_max(a, b) (a > b ? a : b)

int countNumbersWithUniqueDigits(int n) {
    int sum = 0;
    int temp = 9;
    for (int i = 0; i <= n; i++) {
        if (i == 0) sum += 1;
        else if (i == 1) sum += 9;
        else {
            temp *= my_max(0, 11 - i);
            sum += temp;
        }
    }
    return sum;
}
