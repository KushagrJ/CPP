/*

 * https://codeforces.com/blog/entry/105919

 */





#include <iostream>
#include <vector>
#include <algorithm>


int main()
{

    int t;
    std::cin >> t;

    std::vector<int> v(101);

    while (t--)
    {
        int n, k;
        std::cin >> n >> k;

        for (int i = 1; i <= n; ++i)
            std::cin >> v[i];

        int ans = 0;

        for (int i = 1; i <= k; ++i)
        {
            if (v[i] > k)
            {
                int j = (k+1);

                while (v[j] > k)
                    ++j;

                std::swap(v[i], v[j]);

                ++(ans);
            }
        }

        std::cout << ans << '\n';
    }

    return 0;

}
