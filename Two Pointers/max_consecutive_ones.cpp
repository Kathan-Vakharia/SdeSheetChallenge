#include <bits/stdc++.h>

using namespace std;

/*
-Time:O(n)
-Space:O(1)
*/
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int count = 0;
        int maxi = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                count = 0;
            else //nums[i] == 1
                count++;

            //update max at every iteration
            maxi = max(count, maxi);
        }
        return maxi;
    }
};
int main()
{

    return 0;
}