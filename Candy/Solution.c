int candy(int* ratings, int ratingsSize) {
    int* cnts = (int*) malloc(ratingsSize * sizeof(int));
    int sum = 0;
    cnts[0] = 1;
    for (int i = 1; i < ratingsSize; i++) {
        cnts[i] = ratings[i] > ratings[i - 1] ? cnts[i - 1] + 1 : 1;
    }
    sum += cnts[ratingsSize - 1];
    for (int i = ratingsSize - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1] && cnts[i + 1] + 1 > cnts[i]) {
            cnts[i] = cnts[i + 1] + 1;
        }
        sum += cnts[i];
    }
    return sum;
}
