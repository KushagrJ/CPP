#include <iostream>


const int a[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000,
                   100000000, 1000000000};


int main()
{

    int t;
    std::cin >> t;

    while (t--)
    {
        int m;
        std::cin >> m;

        int i = 9;
        while (a[i] > m)
            --i;

        std::cout << (m - a[i]) << '\n';
    }

    return 0;

}
