/*

 * https://codeforces.com/blog/entry/106136

 */





#include <iostream>


int main()
{

    int t;
    std::cin >> t;

    while (t--)
    {
        long long a, b, c, d;
        std::cin >> a >> b >> c >> d;

        if ((a == 0) && (c == 0))
            std::cout << "0\n";
        else if ((a == 0) || (c == 0))
            std::cout << "1\n";
        else if ((a * d) == (b * c))
            std::cout << "0\n";
        else if (((b * c) % (a * d) == 0) || ((a * d) % (b * c) == 0))
            std::cout << "1\n";
        else
            std::cout << "2\n";
    }

    return 0;

}
