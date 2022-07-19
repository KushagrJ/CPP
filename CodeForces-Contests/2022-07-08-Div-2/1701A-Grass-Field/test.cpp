/*

 * https://codeforces.com/blog/entry/104671

 */





#include <iostream>


int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int number_of_ones = 0;

        for (int i = 0; i < 4; ++i)
        {
            int a;
            std::cin >> a;

            if (a == 1)
                ++(number_of_ones);
        }

        if (number_of_ones == 0)
            std::cout << "0\n";
        else if (number_of_ones == 4)
            std::cout << "2\n";
        else
            std::cout << "1\n";
    }

    return 0;
}
