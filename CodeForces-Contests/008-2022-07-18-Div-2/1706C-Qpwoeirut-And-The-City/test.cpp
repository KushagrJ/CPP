/*

 * https://codeforces.com/blog/entry/105008

 */





#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>


int main()
{

    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;

        std::vector<int> v(n+1);
        for (int i = 1; i <= n; ++i)
            std::cin >> v[i];

        if (n & 1)
        {
            long long ans = 0;

            for (int i = 2; i < n; i += 2)
                if (v[i] <= std::max(v[i-1], v[i+1]))
                    ans += (std::max(v[i-1], v[i+1]) - v[i] + 1);

            std::cout << ans << '\n';
        }

        else
        {
            std::vector<long long> even(n/2);
            even[0] = 0;

            std::vector<long long> odd(n/2);
            odd[0] = 0;

            for (int i = 2, j = 1; i < n; i += 2, ++j)
            {
                if (v[i] <= std::max(v[i-1], v[i+1]))
                    even[j] = (std::max(v[i-1], v[i+1]) - v[i] + 1);
                else
                    even[j] = 0;

                if (v[i+1] <= std::max(v[i], v[i+2]))
                    odd[j] = (std::max(v[i], v[i+2]) - v[i+1] + 1);
                else
                    odd[j] = 0;
            }

            for (int i = 1; i < (n/2); ++i)
            {
                even[i] += even[i-1];
                odd[i] += odd[i-1];
            }

            long long ans = std::numeric_limits<long long>::max();

            for (int i = 0; i < (n/2); ++i)
                if (((even[i] - even[0]) + (odd[(n/2) - 1] - odd[i])) < ans)
                    ans = ((even[i] - even[0]) + (odd[(n/2) - 1] - odd[i]));

            std::cout << ans << '\n';
        }
    }

    return 0;

}
