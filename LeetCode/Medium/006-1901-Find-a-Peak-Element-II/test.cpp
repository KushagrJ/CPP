/*

 * It is given that at least one peak exists, and no two adjacent cells' values
   are equal.

   Let max be the index for the rows, and lo, mid & hi be the indices for the
   columns.

   Now, binary search can be used to find a peak, with lo == 0 and
   hi == (mat[0].length - 1) initially.

   In the mid column, a cell having the highest value is found.
   This cell's value will definitely be greater than the values of the cells
   above and below it.

   Now, if the value of the cell to the left of this cell is greater than or
   equal to this cell's value, then we can be sure that at least one peak
   exists in the columns lo to (mid - 1).

   Similarly, if the value of the cell to the right of this cell is greater
   than or equal to this cell's value, then we can be sure that at least one
   peak exists in the columns (mid + 1) to hi.

   Else, if the value of this cell is greater than the values of the cells
   to the left and to the right of this cell, then this cell is a peak.

 */





class Solution
{

    public:

    vector<int> findPeakGrid(vector<vector<int>>& mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        int i = 0, j = 0;

        while (true)
        {
            if (mat[i][j] <= ((i-1 == -1) ? -1 : mat[i-1][j]))
                --i;
            else if (mat[i][j] <= ((j+1 == n) ? -1 : mat[i][j+1]))
                ++j;
            else if (mat[i][j] <= ((i+1 == m) ? -1 : mat[i+1][j]))
                ++i;
            else if (mat[i][j] <= ((j-1 == -1) ? -1 : mat[i][j-1]))
                --j;
            else
                return {i, j};
        }
    }

};
