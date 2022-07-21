/*

 * https://codeforces.com/blog/entry/104763

 */





#include <iostream>
#include <map>


int main()
{

    int t;
    std::cin >> t;

    while (t--)
    {
        int n, k;
        std::cin >> n >> k;

        std::map<int, int> first;
        std::map<int, int> last;

        for (int i = 0; i < n; ++i)
        {
            int u;
            std::cin >> u;

            if ((first.count(u) == 0) || (first[u] > i))
                first[u] = i;

            if ((last.count(u) == 0) || (last[u] < i))
                last[u] = i;
        }

        while (k--)
        {
            int a, b;
            std::cin >> a >> b;

            if ((first.count(a) > 0) && (first.count(b) > 0))
            {
                if (first[a] <= last[b])
                    std::cout << "YES\n";
                else
                    std::cout << "NO\n";
            }

            else
            {
                std::cout << "NO\n";
            }
        }
    }

    return 0;

}
