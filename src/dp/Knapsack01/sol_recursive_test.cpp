#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

class Solution {
 private:
  int TryKnapsack01(const vector<int> &w, const vector<int> &v, int i, int c) {
    if (i < 0 || c <= 0) {
      return 0;
    }

    int ans = TryKnapsack01(w, v, i - 1, c);

    if (c >= w[i]) {
      ans = max(ans, v[i] + TryKnapsack01(w, v, i - 1, c - w[i]));
    }
    return ans;
  }

 public:
  int Knapscak01(const vector<int> &w, const vector<int> &v, int c) {
    assert(w.size() == v.size());
    assert(c >= 0);
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