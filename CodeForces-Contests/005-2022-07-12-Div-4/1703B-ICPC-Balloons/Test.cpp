#include <iostream>


int main()
{

    int t;
    std::cin >> t;
    getchar();

    while (t--)
    {
        bool has_been_solved[26] = {false};

        int n;
        std::cin >> n;
        getchar();

        int ans = 0;

        int c;

        while (((c = getchar()) != '\n') && (c != EOF))
        {
            if (has_been_solved[c - 'A'])
            {
                ans += 1;
            }

            else
            {
                ans += 2;
                has_been_solved[c - 'A'] = true;
            }
        }

        std::cout << ans << '\n';
    }

    return 0;

}
