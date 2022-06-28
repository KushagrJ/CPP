class Solution
{

    public:

    vector<vector<char>> rotateTheBox(vector<vector<char>>& box)
    {

        int m = (box.size());
        int n = (box[0].size());

        for (int i = 0; i < m; i++)
        {
            int end = (n-1);

            for (int j = (n-1); j >= 0; j--)
            {
                if (box[i][j] == '#')
                {
                    box[i][j] = '.';
                    box[i][end] = '#';
                    --(end);
                }

                else if (box[i][j] == '*')
                {
                    end = (j-1);
                }
            }
        }

        vector<vector<char>> ans(n, vector<char>(m));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ans[j][m-1-i] = box[i][j];

        return ans;

    }

};
