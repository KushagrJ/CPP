/*

 * https://codeforces.com/blog/entry/105419

 */





#include <iostream>
#include <vector>
#include <algorithm>


int main()
{

    int squares[320];
    for (int i = 0; i < 320; ++i)
        squares[i] = (i*i);

    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;

        std::vector<int> v(n);

        int i = (n-1);

        while (i >= 0)
        {
            int sq =
                *(std::lower_bound(std::begin(squares), std::end(squares), i));

            int prev_i = i;
            while (i >= (sq - prev_i))
            {
                v[i] = (sq - i);
                --i;
            }
        }

        for (int z = 0; z < n; ++z)
            std::cout << v[z] << ' ';
        std::cout << '\n';
    }

    return 0;

}
