#include <bits/stdc++.h>
using namespace std;
/*
- Time:O(n^2)
- Space:O(1)
*/

class Solution
{
public:
    //Super Naive Approach
    int trap(vector<int> &height)
    {
        if (height.empty())
            return 0;
        
        //go to every base and calculate water stored at that point
        //Note: water[i] = Min(MaxL, MaxR) - Arr[i]
        int result = 0;
        //water won't be stored at first base
        for (int i = 1; i < height.size(); i++)
        {

            //calculate MaxL
            int left_max = height[i];
            for (int j = i - 1; j >= 0; j--)
                left_max = max(left_max, height[j]);

            //calculate MaxR
            int right_max = height[i];
            for (int k = i + 1; k < height.size(); k++)
                right_max = max(right_max, height[k]);

            //update result
            result += min(left_max, right_max) - height[i];
        }
        return result;
    }
};
