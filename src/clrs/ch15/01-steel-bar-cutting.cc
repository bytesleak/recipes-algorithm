#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;


class Solution{
public:
    int SteelBarCutting(int n, const vector<int>& prices, int* income) {
        vector<int> dp_table_for_cutlen(n + 1, 0); /// 记录长度为 n 的钢条在位置 i 按照什么长度切割产生的最大值
        vector<int> dp_table_for_income(n + 1, 0); /// 记录长度为 n 的钢条切割所能获得最大的收益
        for (int i = 1; i <= n; i++ ){
            int q = prices[i-1];
            dp_table_for_cutlen[i] = i;
            dp_table_for_income[i] = q;
            for (int j = 1; j < i; j++) {
                if (prices[j-1] + prices[i-j-1] > q) {
                    q = prices[j-1] + prices[i-j-1];
                    dp_table_for_cutlen[i] = j;
                }
            }
            dp_table_for_income[i] = q;
        }
        *income = dp_table_for_income[n];
        return dp_table_for_cutlen[n];
    }
};


int main() {
    Solution sol;
    int n = 10;
    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int income = std::numeric_limits<int>::min();
    int len = sol.SteelBarCutting(n, prices, &income);
    cout << len << ", " << income << endl;
}