/*

 * https://codeforces.com/blog/entry/105008

 */





#include <iostream>
#include <vector>


int main()
{

    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;

        std::vector<int> last_position((n+1), 0);
        std::vector<int> ans((n+1), 0);

        for (int i = 1; i <= n; ++i)
        {
            int c;
            std::cin >> c;

            if ((last_position[c] == 0) || ((i - last_position[c]) & 1))
            {
                last_position[c] = i;
                ++(ans[c]);
            }
        }

        for (int i = 1; i <= n; ++i)
            std::cout << ans[i] << ' ';
        std::cout << '\n';
    }

    return 0;

}
