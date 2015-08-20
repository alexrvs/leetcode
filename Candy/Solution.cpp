class Solution {
public:
  int candy(vector<int> &ratings) {
    int num = ratings.size();
    vector<int> candies(num, 1);
    candies[0] = 1;
    for (int i = 1; i < num; i++) {
      if (ratings[i] > ratings[i-1]) {
        candies[i] = candies[i-1] + 1;
      } else {
        candies[i] = 1;
      }
    }
    for (int i = num-2; i >= 0; i--) {
      if (ratings[i] > ratings[i+1]) {
        candies[i] = max(candies[i], candies[i+1]+1);
      }
    }
    int sum = 0;
    for (int i = 0; i < num; i++) {
      sum += candies[i];
    }
    return sum;
  }
};
