class NumArray {
private:
    vector<int> *m_nums;
    vector<int> m_sums;
public:
    NumArray(vector<int> &nums) {
        m_nums = &nums;
        m_sums.push_back(0);
        for (int i = 1; i < nums.size(); i++) {
            m_sums.push_back(m_sums[i - 1] + nums[i - 1]);
        }
    }

    int sumRange(int i, int j) {
        return m_sums[j] - m_sums[i] + (*m_nums)[j];
    }
};
