#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
 int calculateIntegerBreak(int n) {
   if (n == 1) {
     return 1;
   }

   if (memo_[n] != -1) {
     return memo_[n];
   }

   for (int i = 1; i < n; i++) {
     memo_[n] = max(memo_[n], max (i * (n-i), i  * calculateIntegerBreak(n-i)));
   }
   return memo_[n];
 }

 vector<int> memo_;
public:
 int integerBreak(int n) {
   memo_ = vector<int>(n+1, -1);
   return calculateIntegerBreak(n);
 }
};

int main() {
  Solution sol;
  cout << sol.integerBreak(58) << endl;
}
