#include <bits/stdc++.h>
using namespace std;

/*
-Time:O(n) {In worst case, two scans are required}
-Space:O(1)
*/
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {

        // find 'i' such that 'nums[i] > nums[i-1]' from RIGHT
        int i = nums.size() - 1;
        while (i >= 1 and nums[i] <= nums[i - 1])
            i--;
        if (i > 0)
        { // if nums is not in DSC order

            // find element just larger than nums[i-1]
            int j = nums.size() - 1;
            while (nums[j] <= nums[i - 1])
                j--;
            swap(nums[i - 1], nums[j]);
        }

        // reverse the sub-array nums[i...]
        reverse(nums.begin() + i, nums.end());
    }
};
