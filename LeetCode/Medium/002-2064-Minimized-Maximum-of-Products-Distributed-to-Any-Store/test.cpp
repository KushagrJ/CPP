/*

 * Use a function which checks whether k is the value of a possible solution to
   the problem, and use this function to (binary) search the smallest possible
   value of k.

   Note that if a particular k is the value of a possible solution to the
   problem, i.e. if all products can be distributed such that every store gets
   less than or equal to k products, then (k+1), (k+2), ... are all values of
   possible solutions to the problem.

 */





class Solution
{

    public:

    bool x_is_a_possible_answer(int n, vector<int>& q, int x)
    {
        unsigned long long count = 0;

        for (int i : q)
            // This performs unsigned ceiling division.
            count += ((i / x) + (i % x != 0));

        if (count <= static_cast<unsigned long long>(n))
            return true;
        else
            return false;
    }

    int minimizedMaximum(int n, vector<int>& q)
    {
        int start = 1;
        int end = 1;

        while (!(x_is_a_possible_answer(n, q, end)))
        {
            start = (end + 1);
            end *= 2;
        }

        while (start < end)
        {
            int middle = (start + ((end - start) / 2));

            if (x_is_a_possible_answer(n, q, middle))
                end = middle;
            else
                start = (middle + 1);
        }

        // At this point, start == end.
        return start;
    }

};
