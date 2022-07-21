/*

 * https://codeforces.com/blog/entry/104786

 */





#include <iostream>
#include <cstdio>


int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;

        int arr[100][100];

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%1d", &(arr[i][j]));

        int ans = 0;

        for (int i = 0; i < ((n + 1) / 2); ++i)
        {
            int a1 = i, b1 = i;
            int a2 = i, b2 = (n - i - 1);
            int a3 = (n - i - 1), b3 = (n - i - 1);
            int a4 = (n - i - 1), b4 = i;

            while (b1 != (n - i - 1))
            {
                int zeroes = 0, ones = 0;

                ((arr[a1][(b1)++]) == 0 ? ++(zeroes) : ++(ones));
                ((arr[(a2)++][b2]) == 0 ? ++(zeroes) : ++(ones));
                ((arr[a3][(b3)--]) == 0 ? ++(zeroes) : ++(ones));
                ((arr[(a4)--][b4]) == 0 ? ++(zeroes) : ++(ones));

                ans += std::min(zeroes, ones);
            }
        }

        std::cout << ans << '\n';
    }

    return 0;
}
