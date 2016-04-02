class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        int size = num.size();
        vector<vector<int> > ret;

        if (size == 1) {
            ret.push_back(num);
            return ret;
        }
        vector<vector<int> > post;

        vector<int> cur;
        vector<int> tmp;

        for (int i = 0; i < size; i++) {
            cur = num;
            cur.erase(cur.begin() + i);
            post = permute(cur);
            for (int j = 0; j < post.size(); j++) {
                tmp = post[j];
                tmp.insert(tmp.begin(), num[i]);
                ret.push_back(tmp);
            }
        }

        return ret;
    }
};
