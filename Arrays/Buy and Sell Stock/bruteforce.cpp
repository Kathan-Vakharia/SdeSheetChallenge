#include <bits/stdc++.h>
using namespace std;

/*
-Time:O(n^2)
-Space:O(1)
*/
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        for (int i = 0; i < prices.size(); i++)
            for (int j = i + 1; j < prices.size(); j++)
            {
                int t = prices[j] - prices[i];
                if (t > profit)
                    profit = t;
            }
        return profit;
    }
};