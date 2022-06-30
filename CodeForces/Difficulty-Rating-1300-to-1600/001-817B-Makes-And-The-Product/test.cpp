#include <iostream>


int main()
{

    unsigned long long n;
    std::cin >> n;
    n -= 2;

    unsigned long long x, y;
    std::cin >> x >> y;

    unsigned long long min_1 = ((x < y) ? x : y);
    unsigned long long count_1 = ((x == y) ? 2 : 1);

    unsigned long long min_2 = (x * y);
    unsigned long long count_2 = 1;

    __uint128_t min_3 = static_cast<__uint128_t>(-1);
    unsigned long long count_3 = 1;

    while (n--)
    {
        unsigned long long a;
        std::cin >> a;

        unsigned long long b = (min_1 * a);

        __uint128_t c = (static_cast<__uint128_t>(min_2) * a);

        if (c == min_3)
            count_3 = (count_2 + count_3);
        else if (c < min_3)
            (min_3 = c), (count_3 = count_2);

        if (b == min_2)
            count_2 = (count_1 + count_2);
        else if (b < min_2)
            (min_2 = b), (count_2 = count_1);

        if (a == min_1)
            ++(count_1);
        else if (a < min_1)
            (min_1 = a), (count_1 = 1);
    }

    std::cout << count_3 << '\n';

    return 0;

}
