/*

 * Keep shifting the stones one by one towards the right, starting with the
   rightmost stone in every row of the box.

 */





class Solution
{

    public:

    vector<vector<char>> rotateTheBox(vector<vector<char>>& box)
    {
        int m = (box.size());
        int n = (box[0].size());

        for (int i = 0; i < m; i++)
        {
            for (int j = (n - 1); j >= 0; j--)
            {
                if (box[i][j] == '#')
                {
                    int k = (j + 1);

                    while ((k < n) && (box[i][k] == '.'))
                        ++k;

                    if (j != (k-1))
                        swap(box[i][j], box[i][k-1]);
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
