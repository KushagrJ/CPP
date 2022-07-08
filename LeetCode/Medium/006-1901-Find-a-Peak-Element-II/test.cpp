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
