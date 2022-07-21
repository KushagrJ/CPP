/*

 * https://codeforces.com/blog/entry/104786

 */





#include <iostream>
#include <vector>
#include <algorithm>


int main()
{

    int t;
    std::cin >> t;

    while (t--)
    {
        int n, k;
        std::cin >> n >> k;

        std::vector<int> v(n+1);
        for (int i = 1; i <= n; ++i)
            std::cin >> v[i];

        long long maximum_coins = 0;
        long long coins_after_using_consecutive_good_keys = 0;

        // i is the number of consecutive good keys used.
        for (int i = 0; i <= n; ++i)
        {
            long long temp_coins = coins_after_using_consecutive_good_keys;

            for (int j = (i+1); j <= std::min(n, (i+32)); ++j)
            {
                int temp = v[j];

                for (int z = 0; z < (j-i); ++z)
                    temp /= 2;

                temp_coins += temp;
            }

            maximum_coins = std::max(maximum_coins, temp_coins);

            if ((i+1) <= n)
                coins_after_using_consecutive_good_keys += (v[i+1] - k);
        }

        std::cout << maximum_coins << '\n';
    }

    return 0;

}
