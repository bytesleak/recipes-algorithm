#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
 private:
  int CalculateFibonacci(int n) {
    if (n == 0) {
      return 0;
    }
    if (n == 1) {
      return 1;
    }
    if (memo_[n] != -1)  {
      return memo_[n];
    }
    memo_[n] = CalculateFibonacci(n - 1) + CalculateFibonacci(n - 2);
    return memo_[n];
  }

  vector<int> memo_;
 public:
  int fibonacci(int n)  {
    assert(n >= 0);
    memo_ = vector<int>(n + 1, -1);
    return CalculateFibonacci(n);
  }
};

int main() {
  Solution sol;
  cout << sol.fibonacci(40) << endl;
}