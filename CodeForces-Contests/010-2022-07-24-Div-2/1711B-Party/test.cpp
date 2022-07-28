#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <limits>


int main()
{

    int t;
    std::cin >> t;

    while (t--)
    {
        int n, m;
        std::cin >> n >> m;

        // v[i].first is the unhappiness value corresponding to member i.
        // v[i].second is the number of friends of member i.
        std::vector<std::pair<int, int>> v(n+1, std::make_pair(0, 0));

        // v2[] stores the friendships.
        std::vector<std::pair<int, int>> v2(m+1);

        for (int i = 1; i <= n; ++i)
        {
            int a;
            std::cin >> a;

            v[i].first = a;
        }

        for (int i = 1; i <= m; ++i)
        {
            int x, y;
            std::cin >> x >> y;

            v2[i].first = x;
            v2[i].second = y;

            ++(v[x].second);
            ++(v[y].second);
        }

        if (m & 1)
        {
            int ans = std::numeric_limits<int>::max();

            for (int i = 1; i <= n; ++i)
                if (((v[i].second) & 1) && (v[i].first < ans))
                    ans = v[i].first;

            for (int i = 1; i <= m; ++i)
            {
                if (((v[v2[i].first].second & 1) == 0) &&
                       ((v[v2[i].second].second & 1) == 0))
                {
                    if ((v[v2[i].first].first + v[v2[i].second].first) < ans)
                    {
                        ans = (v[v2[i].first].first + v[v2[i].second].first);
                    }
                }
            }

            std::cout << ans << '\n';
        }

        else
        {
            std::cout << 0 << '\n';
        }
    }

    return 0;

}
