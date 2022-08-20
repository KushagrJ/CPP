/*

 * https://codeforces.com/blog/entry/106049

 */





#include <iostream>


int main()
{

    int t;
    std::cin >> t;

    while (t--)
    {
        int n, k;
        std::cin >> n >> k;

        if (k % 4 == 0)
        {
            std::cout << "NO\n";
        }

        else
        {
            std::cout << "YES\n";

            if (k & 1)
            {
                for (int i = 1; i <= n; i += 2)
                    std::cout << i << ' ' << (i+1) << '\n';
            }

            else
            {
                int i = -1;

                for (int j = 4; j <= n; j += 4)
                    std::cout << (i += 2) << ' ' << j << '\n';

                for (int j = 2; j <= n; j += 4)
                    std::cout << j << ' ' << (i += 2) << '\n';
            }
        }
    }

    return 0;

}
