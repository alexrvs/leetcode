class Solution {
private:
    int convert(string time) {
        int idx = -1;
        int hour = 0;
        int mins = 0;
        for (int i = 0; i < time.size(); i++) {
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
    
public:
    int findMinDifference(vector<string>& timePoints) {
        int size = timePoints.size();
        vector<int> minutes;
        for (int i = 0; i < size; i++) {
            minutes.push_back(convert(timePoints[i]));
        }
        sort(minutes.begin(), minutes.end());
        int res = 1440 - (minutes[size - 1] - minutes[0]);
        for (int i = 1; i < minutes.size(); i++) {
            int diff = minutes[i] - minutes[i - 1];
            if (res > diff) {
                res = diff;
            }
        }
        return res;
    }
};