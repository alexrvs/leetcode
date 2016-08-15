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
struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) {
    if (intervalsSize == 0) return NULL;
    struct Interval* res = (struct Interval*) malloc(intervalsSize * sizeof(struct Interval));
    qsort(intervals, intervalsSize, sizeof(struct Interval), compInterval);
    res[0].start = intervals[0].start;
    res[0].end = intervals[0].end;
    *returnSize = 1;
    for (int i = 1; i < intervalsSize; i++) {
        if (res[*returnSize - 1].end < intervals[i].start) {
            *returnSize += 1;
            res[*returnSize - 1].start = intervals[i].start;
            res[*returnSize - 1].end = intervals[i].end;
        } else {
            if (res[*returnSize - 1].end < intervals[i].end) {
                res[*returnSize - 1].end = intervals[i].end;
            }
        }
    }
    return res;
}
