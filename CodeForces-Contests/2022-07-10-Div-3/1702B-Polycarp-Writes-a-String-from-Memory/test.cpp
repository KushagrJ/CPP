/*

 * https://codeforces.com/blog/entry/104763

 */





#include <iostream>
#include <set>


int main()
{

    std::set<int> s;

    int t;
    std::cin >> t;
    getchar();

    while (t--)
    {
        s.clear();

        int minimum_number_of_days = 1;

        int c;

        while (((c = getchar()) != '\n') && (c != EOF))
        {
            s.insert(c);

            if (s.size() == 4)
            {
                ++(minimum_number_of_days);
                s.clear();
                s.insert(c);
            }
        }

        std::cout << minimum_number_of_days << '\n';
    }

    return 0;

}
