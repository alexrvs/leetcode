int convert(char* time) {
    int idx = -1;
    int hour = 0;
    int mins = 0;
    int size = strlen(time);
    for (int i = 0; i < size; i++) {
        if (time[i] == ':') {
            idx = i;
        } else if (idx < 0) {
            hour = hour * 10 + time[i] - '0';
        } else {
            mins = mins * 10 + time[i] - '0';
        }
    }
    return 60 * hour + mins;
}

int compare(void* a, void* b) {
    int* ia = (int*) a;
    int* ib = (int*) b;
    return *ia - *ib;
}

int findMinDifference(char** timePoints, int timePointsSize) {
    int size = timePointsSize;
    int* minutes = (int*) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        minutes[i] = convert(timePoints[i]);
    }
    qsort(minutes, size, sizeof(int), compare);
    int res = 1440 - (minutes[size - 1] - minutes[0]);
    for (int i = 1; i < size; i++) {
        int diff = minutes[i] - minutes[i - 1];
        if (res > diff) {
            res = diff;
        }
    }
    return res;
}