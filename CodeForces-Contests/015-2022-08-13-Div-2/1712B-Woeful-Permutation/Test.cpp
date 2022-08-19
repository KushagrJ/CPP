/*

 * https://codeforces.com/blog/entry/105919

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

        if (n & 1)
        {
            std::cout << "1 ";

            for (int i = 3; i <= n; i += 2)
                std::cout << i << ' ' << (i-1) << ' ';

            std::cout << '\n';
        }

        else
        {
            for (int i = 2; i <= n; i += 2)
                std::cout << i << ' ' << (i-1) << ' ';

            std::cout << '\n';
        }
    }

    return 0;

}
