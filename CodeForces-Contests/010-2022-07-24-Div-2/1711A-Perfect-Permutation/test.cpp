/*

 * https://codeforces.com/blog/entry/105232

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

        std::cout << n << ' ';

        for (int i = 1; i < n; ++i)
            std::cout << i << ' ';

        std::cout << '\n';
    }

    return 0;

}
