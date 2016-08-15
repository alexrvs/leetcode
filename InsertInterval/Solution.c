/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */

static int compInterval(const void* a, const void* b) {
    struct Interval* inta = (struct Interval*) a;
    struct Interval* intb = (struct Interval*) b;
    return inta->start - intb->start;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct Interval* insert(struct Interval* intervals, int intervalsSize, struct Interval newInterval, int* returnSize) {
    struct Interval* res = (struct Interval*) malloc((intervalsSize + 1) * sizeof(struct Interval));
    if (intervalsSize > 0) {
        memcpy(res, intervals, intervalsSize * sizeof(struct Interval));
    }
    res[intervalsSize].start = newInterval.start;
    res[intervalsSize].end = newInterval.end;
    qsort(res, intervalsSize + 1, sizeof(struct Interval), compInterval);
    *returnSize = 1;
    for (int i = 1; i <= intervalsSize; i++) {
        if (res[*returnSize - 1].end < res[i].start) {
            *returnSize += 1;
            res[*returnSize - 1].start = res[i].start;
            res[*returnSize - 1].end = res[i].end;
        } else {
            if (res[*returnSize - 1].end < res[i].end) {
                res[*returnSize - 1].end = res[i].end;
            }
        }
    }
    return res;
}
