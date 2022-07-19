/*

 * https://codeforces.com/blog/entry/104310

 */





#include <iostream>


int main()
{

    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;

        int lo = 1;
        int hi = n;

        while (lo < hi)
        {
            int mid = (lo + ((hi - lo) / 2));

            std::cout << "? " << lo << ' ' << mid << std::endl;

            int count = 0;

            int number_of_integers_to_read = (mid - lo + 1);

            while ((number_of_integers_to_read)--)
            {
                int a;
                std::cin >> a;

                if ((lo <= a) && (a <= mid))
                    ++(count);
            }

            if (count & 1)
                hi = mid;
            else
                lo = (mid + 1);
        }

        std::cout << "! " << lo << std::endl;
    }

    return 0;

}
