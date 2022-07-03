#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


int main()
{

    // Since the string is stored using 0-based indexing, therefore 1 will have
    // to be subtracted when subscripting.
    std::string s;
    std::cin >> s;

    // The 0-th element of this vector is unused, making the indexing 1-based.
    std::vector<int> swap_count(((s.size() / 2) + 1), 0);

    int m;
    std::cin >> m;

    while (m--)
    {
        int a;
        std::cin >> a;

        ++(swap_count[a]);
    }

    for (int i = 2; i <= (s.size() / 2); ++i)
        swap_count[i] += swap_count[i-1];

    for (int i = 1, j = s.size(); i < j; ++i, --j)
        if (swap_count[i] & 1)
            std::swap(s[i-1], s[j-1]);

    std::cout << s << '\n';

    return 0;

}
