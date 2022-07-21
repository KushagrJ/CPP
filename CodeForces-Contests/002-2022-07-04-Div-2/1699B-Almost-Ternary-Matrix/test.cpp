/*

 * https://codeforces.com/blog/entry/104088

 */





#include <iostream>


int main()
{

    int a[50][50];

    int t;
    std::cin >> t;

    while (t--)
    {
        int n, m;
        std::cin >> n >> m;

        for (int i = 0; i < n; i += 2)
        {
            for (int j = 0; j < m; j += 2)
            {
                if (((i + j) % 4) == 0)
                    a[i][j] = 1, a[i][j+1] = 0, a[i+1][j] = 0, a[i+1][j+1] = 1;
                else
                    a[i][j] = 0, a[i][j+1] = 1, a[i+1][j] = 1, a[i+1][j+1] = 0;
            }
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                std::cout << a[i][j] << ' ';
            }

            std::cout << '\n';
        }
    }

    return 0;

}
