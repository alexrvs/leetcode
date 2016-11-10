/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
private:
    static int compare(const Interval& a, const Interval& b) {
        return a.end < b.end;
    }
    
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int size = intervals.size();
        if (size < 1) return 0;
        int cnt = 1;
        int lastEnd = intervals[0].end;
        for (int i = 1; i < size; i++) {
            if (intervals[i].start >= lastEnd) {
                cnt++;
                lastEnd = intervals[i].end;
            }
        }
        return size - cnt;
    }
};