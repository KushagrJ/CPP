/*

 * https://codeforces.com/blog/entry/105549

 */





// The logic of this program works on the basis of 0-indexing.

#include <iostream>
#include <vector>
#include <string>


int main()
{

    int q;
    std::cin >> q;

    while (q--)
    {
        std::string t;
        std::cin >> t;

        int n;
        std::cin >> n;

        // v[i].second stores the ending index of the longest substring which
        // can be coloured in one step, with that substring's starting index
        // being i.
        // v[i].first stores the index of the string which can be used to colour
        // this substring.
        std::vector<std::pair<int, int>> v(t.size(), std::make_pair(-1, -1));

        for (int i = 0; i < n; ++i)
        {
            std::string s;
            std::cin >> s;

            int j = t.find(s, 0);

            while (j != std::string::npos)
            {
                if (static_cast<int>(j + s.size() - 1) > v[j].second)
                {
                    v[j].second = (j + s.size() - 1);
                    v[j].first = i;
                }

                j = t.find(s, (j+1));
            }
        }

        std::vector<std::pair<int, int>> ans;

        // x is the starting index of the remaining part of the string which
        // needs to be coloured.
        // At any instant, the string from index 0 to index (x-1) has already
        // been coloured red.
        int x = 0, i = 0;

        while (x < t.size())
        {
            std::pair<int, int> current = std::make_pair(-1, -1);

            int z;

            while (i <= x)
            {
                if ((v[i].second >= x) && (v[i].second > current.second))
                {
                    current = v[i];
                    z = i;
                }

                ++i;
            }

            if (current.second == -1)
                break;

            ans.push_back(std::make_pair(current.first, z));

            x = (current.second + 1);
        }

        if (x < t.size())
        {
            std::cout << "-1\n";
        }

        else
        {
            std::cout << ans.size() << '\n';
            for (auto z : ans)
                std::cout << (z.first + 1) << ' ' << (z.second + 1) << '\n';
        }
    }

    return 0;

}
