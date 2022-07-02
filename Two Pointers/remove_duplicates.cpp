#include <bits/stdc++.h>
using namespace std;

/*
-Time:O(n)
-Space:O(1)
*/
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;

        int cur = nums[0];
        int size = nums.size();
        int i = 0;
        for (int j = 1; j < size; j++)
        {

            if (nums[j] != cur)
            {
                cur = nums[j];
                swap(nums[++i], nums[j]);
            }
        }
        return i + 1;
    }
};
int main()
{

    return 0;
}