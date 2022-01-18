#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  /// TryKnapsack01 求解在容量为c的背包下, 物品 [0,...,i] 所能放的子集的最优解
  int TryKnapsack01(const vector<int> &w, const vector<int> &v, int i, int c) {
    if (i < 0 || c <= 0) {
      return 0;
    }

    if (memo_[i][c] != -1) {
      return memo_[i][c];
    }

    /// 不包括第 i 个物品的子集的最优解
    int ans = TryKnapsack01(w, v, i - 1, c);

    /// 包括第 i 个物品的子集的最优解
    if (c >= w[i]) {
      ans = max(ans, v[i] + TryKnapsack01(w, v, i - 1, c - w[i]));
    }
    memo_[i][c] = ans;
    return ans;
  }

  vector<vector<int>> memo_;

 public:
  int Knapscak01(const vector<int> &w, const vector<int> &v, int c) {
    assert(w.size() == v.size());
    assert(c >= 0);
    memo_ = vector<vector<int>>(w.size(), vector<int>(c + 1, -1));
    return TryKnapsack01(w, v, w.size() - 1, c);
  }
};

int main() {
  vector<int> w = {2, 1, 3, 2};
  vector<int> v = {12, 10, 20, 15};
  int c = 5;
  Solution sol;
  assert(sol.Knapscak01(w, v, c) == 37);
}