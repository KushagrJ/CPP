/*

 * https://codeforces.com/blog/entry/104881

 */





#include <iostream>
#include <algorithm>


int main()
{
    int a[201];

    int t;
    std::cin >> t;

    while (t--)
    {
        int n, x;
        std::cin >> n >> x;

        for (int i = 1; i <= (2 * n); ++i)
            std::cin >> a[i];

        std::sort(std::begin(a) + 1, std::begin(a) + (2 * n) + 1);

        bool ans = true;

        for (int i = 1; i <= n; ++i)
        {
            if ((a[i+n] - a[i]) < x)
            {
                ans = false;
                break;
            }
        }

        if (ans)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }

    return 0;
}
