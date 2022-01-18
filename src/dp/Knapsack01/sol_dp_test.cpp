#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  vector<vector<int>> memo_;

 public:
  int Knapscak01(const vector<int> &w, const vector<int> &v, int c) {
    assert(w.size() == v.size());
    assert(c >= 0);

    int n = w.size();
    memo_ = vector<vector<int>>(n, vector<int>(c + 1, -1));

    /// dp table 初始情况, 物品 0 放入背包 c
    for (int i = 0; i <= c; i++) {
      memo_[0][i] = (i >= w[0] ? v[0] : 0);
    }

    /// 递推
    for (int i = 1; i < n; i++) {
      for (int j = 0; j <= c; j++) {
        if (j - w[i] >= 0) {
          memo_[i][j] = max(memo_[i - 1][j], v[i] + memo_[i - 1][j - w[i]]);
        } else {
          memo_[i][j] = memo_[i - 1][j];
        }
      }
    }
    return memo_[n - 1][c];
  }
};

int main() {
  vector<int> w = {2, 1, 3, 2};
  vector<int> v = {12, 10, 20, 15};
  int c = 5;
  Solution sol;
  assert(sol.Knapscak01(w, v, c) == 37);
}