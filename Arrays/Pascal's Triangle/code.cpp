#include <bits/stdc++.h>
using namespace std;
/*
- Time:O(n*(n+1)) ~ O(n^2)
- Space:O(n*(n+1))  ~ O(n^2)
*/

/*
       1          --> row 0
     1    1       --> row 1
   1    2     1   --> row 2
 1    3     3    1
*/
//note: This approach is bit slow 
vector<vector<long long int>> printPascal(int n)
{
    // initialize 2D vector : {{}}
    vector<vector<long long int>> triangle;

    // Run a loop to calculate 'n' rows of our triangle
    for (int i = 0; i < n; i++)
    {
        //#cols for a given row  = row_idx + 1;
        int n_cols = i + 1;
        // first[0th] and last[n_cols-1th] element are 1.
        vector<long long int> row(n_cols, 1);

        //update row's 2nd through 2nd last element
        for (int j = 1; j < n_cols - 1; j++)
        {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
        // add row to the triangle/matrix
        triangle.push_back(row);
    }
    return triangle;
}
