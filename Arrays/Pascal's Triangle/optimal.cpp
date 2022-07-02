#include <bits/stdc++.h>
using namespace std;

/*
-Time:O(n^2)
-Space:O(n^2)
*/
class Solution
{
public:
    vector<vector<int>> generate(int n)
    {

        // initialize 2D vector : {{}, {}, ...n-times}
        vector<vector<int>> triangle(n);

        // Run a loop to calculate 'n' rows of our triangle
        for (int i = 0; i < n; i++)
        {
            //#cols for a given row  = row_idx + 1;
            int n_cols = i + 1;
            triangle[i].resize(n_cols, 1);

            // first[0th] and last[n_cols-1th] element are 1.
            for (int j = 1; j < n_cols - 1; j++)
            {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }
        return triangle;
    }
};