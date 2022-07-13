/*

 * In order to absolutely make sure that nums[i] is not the average of
   nums[i-1] and nums[i+1], nums[i] should be less than or greater than both
   nums[i-1] and nums[i+1].

   Since nums[] consists of distinct integers, therefore one way to solve this
   problem is to sort nums[], and then put the numbers smaller than the median
   on even indices & the rest on odd indices.

 */





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
