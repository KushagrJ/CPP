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
        int n;
        std::cin >> n;

        std::vector<int> v1;
        std::vector<int> v2;

        for (int i = 1; i <= n; ++i)
        {
            int a;
            std::cin >> a;

            if (a < i)
            {
                v1.push_back(a);
                v2.push_back(i);
            }
        }

        long long ans = 0;

        for (auto a : v1)
        {
            auto i = std::lower_bound(v2.begin(), v2.end(), a);

            ans += (i - v2.begin());
        }

        std::cout << ans << '\n';
    }

    return 0;

}
