class Solution {
private:
    static int comp(pair<int, int> pa, pair<int, int> pb) {
        if (pa.second != pb.second) return pa.second < pb.second;
        return pa.first < pb.first;
    }

public:
    vector<pair<int, int> > reconstructQueue(vector<pair<int, int> >& people) {
        sort(people.begin(), people.end(), comp);
        vector<pair<int, int> > res;
        for (int i = 0; i < people.size(); i++) {
            if (people[i].second == 0) { res.push_back(people[i]); }
            else {
                int cnt = 0;
                for (int j = 0; j < res.size(); j++) {
                    if (res[j].first >= people[i].first) cnt++;
                    if (cnt == people[i].second) {
                        if (j == res.size() - 1 || res[j + 1].first > people[i].first) {
                            res.insert(res.begin() + j + 1, people[i]);
                            break;
                        }
                    }
                }
            }
        }
        return res;
    }
};
