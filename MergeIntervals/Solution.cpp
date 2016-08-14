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
    static int compInterval(Interval a, Interval b) {
        return a.start < b.start;
    }

public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int size = intervals.size();
        vector<Interval> res;
        if (size == 0) return res;
        sort(intervals.begin(), intervals.end(), compInterval);
        res.push_back(intervals[0]);
        for (int i = 1; i < size; i++) {
            if (res.back().end < intervals[i].start) {
                res.push_back(intervals[i]);
            } else {
                if (res.back().end < intervals[i].end) {
                    res.back().end = intervals[i].end;
                }
            }
        }
        return res;
    }
};  
