/*

 * https://codeforces.com/blog/entry/105464

 */





#include <iostream>
#include <vector>
#include <algorithm>


int main()
{

    int t;
    std::cin >> t;

    while (t--)
    {
        int n, m;
        std::cin >> n >> m;

        std::vector<int> infected(m);

        for (int i = 0; i < m; ++i)
            std::cin >> infected[i];

        std::sort(infected.begin(), infected.end());

        // safe[] stores the number of safe houses between the intervals set by
        // the initial infected houses.
        std::vector<int> safe(m);

        safe[0] = ((infected[0] - 1) + (n - infected[m-1]));

        for (int i = 1; i < m; ++i)
            safe[i] = (infected[i] - infected[i-1] - 1);

        std::sort(safe.begin(), safe.end());

        int newly_infected = 0;

        for (int i = (m-1); i >= 0; --i)
        {
            if ((safe[i] - newly_infected) > 2)
            {
                m += (newly_infected + 1);
                newly_infected += 4;
            }

            else if ((safe[i] - newly_infected) == 2)
            {
                m += (newly_infected + 1);
                newly_infected += 2;
            }

            else if ((safe[i] - newly_infected) == 1)
            {
                m += newly_infected;
                newly_infected += 2;
            }

            else
            {
                m += safe[i];
            }
        }

        std::cout << m << '\n';
    }

    return 0;

}
