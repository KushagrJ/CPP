/*

 * https://codeforces.com/blog/entry/104786

 */





#include <iostream>
#include <set>


int main()
{
    std::string strings[100000];

    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;

        std::set<std::string> s;

        for (int i = 0; i < n; ++i)
        {
            std::cin >> strings[i];
            s.insert(strings[i]);
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 1; j < strings[i].size(); ++j)
            {
                if ((s.find(strings[i].substr(0, j)) != s.end()) &&
                       (s.find(strings[i].substr(j)) != s.end()))
                {
                    std::cout << "1";
                    goto end_of_iteration;
                }
            }

            std::cout << "0";

            end_of_iteration: ;
        }

        std::cout << '\n';
    }

    return 0;
}
