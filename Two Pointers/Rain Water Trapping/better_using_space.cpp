#include <bits/stdc++.h>
using namespace std;

/*
-Time:O(n)
-Space:O(n)
*/
class Solution
{
public:
    int trap(vector<int> &height)
    {
        //edge case
        if (height.empty())
            return 0;

        //go to every base and calculate water stored at that point
        //Note: water[i] = Min(MaxL, MaxR) - Arr[i]

        //left_max[i] contains MaxL at ith index(inclusive)
        vector<int> left_max(height.size(), 0);
        left_max[0] = height[0];
        for (int i = 1; i < height.size(); i++)
            left_max[i] = max(left_max[i - 1], height[i]);

        //right_max[i] contains MaxR at ith index(inclusive)
        vector<int> right_max(height.size(), 0);
        right_max[height.size() - 1] = height[height.size() - 1];
        for (int i = height.size() - 2; i >= 0; i--)
            right_max[i] = max(right_max[i + 1], height[i]);

        //water[i] contains water stored at ith base
        vector<int> water(height.size(), 0);
        for (int i = 0; i < water.size(); i++)
        {

            water[i] += min(left_max[i], right_max[i]) - height[i];
        }

        //calculate result
        int result = 0;
        result = accumulate(water.begin(), water.end(), result);

        return result;
    }
};
int main()
{

    return 0;
}