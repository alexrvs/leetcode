int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration) {
    if (timeSeriesSize == 0) return 0;
    int res = duration;
    for (int i = 1; i < timeSeriesSize; i++) {
        int diff = timeSeries[i] - timeSeries[i - 1];
        if (diff > duration) {
            res += duration;
        } else {
            res += diff;
        }
    }
    return res;
}