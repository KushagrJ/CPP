/*

 * The array elements can be thought of as being alternatively strictly
   increasing and strictly decreasing.

   It is given that at least one peak exists, and for all valid i,
   nums[i] != nums[i + 1].

   Thus, binary search can be used to find a peak, with lo == 0 and
   hi == (nums.length - 1) initially.

   If nums[mid] > nums[mid + 1], then we can be sure that at least one peak
   exists to the left of mid, including mid.
   Else if nums[mid] < nums[mid + 1], then we can be sure that at least one
   peak exists to the right of mid, excluding mid.

   The searching stops when lo eventually becomes equal to hi, which gives the
   index of a peak.

 */





class Solution
{

    public:

    int findPeakElement(vector<int>& nums)
    {
        int lo = 0;
        int hi = (nums.size() - 1);

        while (lo < hi)
        {
            int mid = (lo + ((hi - lo) / 2));

            if (nums[mid] > nums[mid + 1])
                hi = mid;
            else
                lo = (mid + 1);
        }

        // At this point, lo == hi.
        return lo;
    }

};
