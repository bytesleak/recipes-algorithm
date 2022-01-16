#include <iostream>
#include <cassert>
#include "gtest/gtest.h"

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

    return CalculateFibonacci(n - 1) + CalculateFibonacci(n - 2);
  }
 public:
  int fibonacci(int n)  {
    assert(n >= 0);
    return CalculateFibonacci(n);
  }
};

TEST(FibonacciProblemTests, RecursiveTests) {
  Solution sol;
  EXPECT_EQ(sol.fibonacci(1), 1);
  EXPECT_EQ(sol.fibonacci(2), 1);
  EXPECT_EQ(sol.fibonacci(3), 2);
  EXPECT_EQ(sol.fibonacci(4), 3);
  EXPECT_EQ(sol.fibonacci(5), 5);
  EXPECT_EQ(sol.fibonacci(6), 8);
  EXPECT_EQ(sol.fibonacci(7), 13);

}