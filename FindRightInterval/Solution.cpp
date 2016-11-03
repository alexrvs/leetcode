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
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        vector<pair<int, int> > starts;
        for (int i = 0; i < intervals.size(); i++) {
            starts.push_back(pair<int, int>(intervals[i].start, i));
        }
        sort(starts.begin(), starts.end());
        vector<int> res;
        for (int i = 0; i < intervals.size(); i++) {
            vector<pair<int, int> >::iterator it = std::lower_bound(starts.begin(), starts.end(), pair<int, int>(intervals[i].end, 0));
            if (it != starts.end()) {
                res.push_back(it->second);
            } else {
                res.push_back(-1);
            }
        }
        return res;
    }
};