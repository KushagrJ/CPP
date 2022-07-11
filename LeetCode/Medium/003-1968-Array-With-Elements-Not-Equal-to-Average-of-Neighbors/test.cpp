class Solution
{

    public:

    std::vector<int> rearrangeArray(std::vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());

        std::vector<int> ans(nums.size());

        int i = 0, j = (nums.size() - 1), k = 0;

        while (i < j)
        {
            ans[k++] = nums[i++];
            ans[k++] = nums[j--];
        }

        if (i == j)
            ans[k++] = nums[i];

        return ans;
    }

};
