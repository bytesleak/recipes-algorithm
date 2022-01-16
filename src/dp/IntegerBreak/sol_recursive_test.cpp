#include <cassert>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
private:
 int calculateIntegerBreak(int n) {
   if (n == 1) {
     return 1;
   }

   int res = -1;
   for (int i = 1; i < n; i++) {
     res = max(res, max (i * (n-i), i  * calculateIntegerBreak(n-i)));
   }
   return res;
 }
public:
 int integerBreak(int n) {
   return calculateIntegerBreak(n);
 }
};

int main() {
  Solution sol;
  cout << sol.integerBreak(58) << endl;
}
