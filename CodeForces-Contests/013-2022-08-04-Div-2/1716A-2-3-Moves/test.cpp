/*

 * https://codeforces.com/blog/entry/105653

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

        if (n == 1)
        {
            std::cout << "2\n";
        }

        else if ((n == 2) || (n == 3))
        {
            std::cout << "1\n";
        }

        else
        {
            std::cout << ((n / 3) + (n % 3 != 0)) << '\n';
        }
    }

    return 0;

}
