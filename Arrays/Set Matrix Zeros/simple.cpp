#include <bits/stdc++.h>
using namespace std;

/*
 > Idea: Maintain arrays for rows and columns to keep track 
 > whether a row/column contains 0 or NOT.
-Time:O(m*n)
-Space:O(m+n)
*/
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n_rows = matrix.size();
        int n_cols = matrix[0].size();
        vector<int> row_flag(n_rows, 0);
        vector<int> col_flag(n_cols, 0);

        // update flag arrays
        for (int i = 0; i < n_rows; i++)
        {
            for (int j = 0; j < n_cols; j++)
            {
                // mark row-i and col-j if a[i][j] is 0
                if (matrix[i][j] == 0)
                {
                    row_flag[i] = 1;
                    col_flag[j] = 1;
                }
            }
        }

        // update matrix
        for (int i = 0; i < n_rows; i++)
        {
            for (int j = 0; j < n_cols; j++)
            {
                if (row_flag[i] == 1 or col_flag[j] == 1)
                    matrix[i][j] = 0;
            }
        }
    }
};
