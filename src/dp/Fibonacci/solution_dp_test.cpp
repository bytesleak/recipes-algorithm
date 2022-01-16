#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
 private:
  vector<int> memo_;
 public:
  int fibonacci(int n)  {
    assert(n >= 0);
    memo_ = vector<int>(n + 1, -1);
    memo_[0] = 0;
    memo_[1] = 1;
    for (int i = 2; i <= n; i++) {
      memo_[i] = memo_[i-1] + memo_[i - 2];
    }
    return memo_[n];
  }
};

int main() {
  Solution sol;
  cout << sol.fibonacci(40) << endl;
}