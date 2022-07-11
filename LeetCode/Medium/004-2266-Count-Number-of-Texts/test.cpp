#define MOD 1000000007


class Solution
{

    public:

    int countTexts(string keys)
    {
        // keys[] is 0-indexed, i.e. 1 is subtracted when subscripting according
        // to the logic of 1-indexing.
        // For eg., keys[(i) - 1] should be read as keys[i], as the minus 1 is
        // there only to convert 1-indexing to 0-indexing.

        // ans[] is 1-indexed.

        vector<unsigned long long> ans(keys.size() + 1);
        ans[0] = 1;

        for (int i = 1; i <= keys.size(); i++)
        {
            ans[i] = ans[i-1];

            if (((i-1) >= 1) && (keys[(i-1) - 1] == keys[(i) - 1]))
            {
                ans[i] += ans[i-2];

                if (((i-2) >= 1) && (keys[(i-2) - 1] == keys[(i) - 1]))
                {
                    ans[i] += ans[i-3];

                    if (((i-3) >= 1) && (keys[(i-3) - 1] == keys[(i) - 1]) &&
                           ((keys[(i) - 1] == '7') || (keys[(i) - 1] == '9')))
                    {
                        ans[i] += ans[i-4];
                    }
                }
            }

            ans[i] %= MOD;
        }

        return ans[keys.size()];
    }

};
