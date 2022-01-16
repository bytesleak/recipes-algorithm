#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  vector<vector<int>> memo_;
 public:
  int integerBreak(int n) {
    memo_ = vector<vector<int>>(n+1, vector<int>(n + 1, -1));
    memo_[1][1] = 1;
    int ans = -1;
    for (int i = 1; i < n; ++i) {
      for (int j = n - i ; j > 1; --j) {
        memo_[i][j] =  max(memo_[i][j], max(i*j, j * memo_[i][j]));
        ans = max(ans, memo_[i][j]);
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  cout << sol.integerBreak(10) << endl;
//  cout << sol.integerBreak(58) << endl;
}
