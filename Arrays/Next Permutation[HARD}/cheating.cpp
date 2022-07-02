#include <bits/stdc++.h>
using namespace std;

/*
-Time:O(n)
-Space:O(1)
*/
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        next_permutation(nums.begin(), nums.end());
    }
};