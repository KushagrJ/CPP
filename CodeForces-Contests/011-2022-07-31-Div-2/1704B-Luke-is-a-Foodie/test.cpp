/*

 * https://codeforces.com/blog/entry/105464

 */





#include <iostream>
#include <limits>
#include <algorithm>


int main()
{

    int t;
    std::cin >> t;

    while (t--)
    {
        int n, x;
        std::cin >> n >> x;

        int ans = 0;

        int lo = std::numeric_limits<int>::min();
        int hi = std::numeric_limits<int>::max();

        while (n--)
        {
            int a;
            std::cin >> a;

            int a_lo = (a - x);
            int a_hi = (a + x);

            lo = std::max(lo, a_lo);
            hi = std::min(hi, a_hi);

            if (lo > hi)
            {
                ++(ans);

                lo = a_lo;
                hi = a_hi;
            }
        }

        std::cout << ans << '\n';
    }

    return 0;

}
