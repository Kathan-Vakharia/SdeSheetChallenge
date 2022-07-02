#include <bits/stdc++.h>
using namespace std;

/*
-Time:O(n)
-Space:O(1)
*/
/*
> Maintain min_price -> stores min price 'till' current day
- I am trying to 'sell everyday'.
- On every day, calculate the difference
- between that day's price and min_price
- if profit is more than max_profit, update
- max_profit.
*/
int maximumProfit(vector<int> &prices)
{
    // initialization
    int min_price = numeric_limits<int>::max();
    int max_profit = 0; // for inputs like: [4,3,2,1]

    // Single Pass through the array
    for (auto price : prices)
    {
        min_price = min(min_price, price);
        max_profit = max(max_profit, price - min_price);
    }
    return max_profit;
}