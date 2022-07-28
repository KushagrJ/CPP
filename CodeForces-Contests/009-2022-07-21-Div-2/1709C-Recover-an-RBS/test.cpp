/*

 * https://youtu.be/hEkoVLTPoiA
   https://codeforces.com/blog/entry/105164

 */





#include <iostream>
#include <string>
#include <algorithm>


int main()
{

    int t;
    std::cin >> t;

    while (t--)
    {
        std::string s;
        std::cin >> s;

        int open = 0;
        int close = 0;
        int ques = 0;

        for (auto c : s)
        {
            switch (c)
            {
                case '(':
                    ++(open);
                    break;
                case ')':
                    ++(close);
                    break;
                default:
                    ++(ques);
            }
        }

        // i.e. if all the question marks can be replaced only by the same
        // character.
        if ((std::max(open, close) - std::min(open, close)) == ques)
        {
            std::cout << "YES\n";
        }

        // i.e. if the question marks need to be replaced by some combination
        // of both the characters.
        else
        {
            int add_open = 0;
            int add_close = 0;

            if (open >= close)
                add_close += (open - close);
            else
                add_open += (close - open);

            int temp = (ques - add_open - add_close);

            add_open += (temp / 2);
            add_close += (temp / 2);

            int last_index_of_add_open;
            int first_index_of_add_close = -1;

            for (int i = 0; i < s.size(); ++i)
            {
                if (s[i] == '?')
                {
                    if (add_open)
                    {
                        s[i] = '(';
                        --(add_open);

                        last_index_of_add_open = i;
                    }

                    else
                    {
                        s[i] = ')';
                        --(add_close);

                        if (first_index_of_add_close == -1)
                            first_index_of_add_close = i;
                    }
                }
            }

            std::swap(s[last_index_of_add_open], s[first_index_of_add_close]);

            bool ans = false;

            long long sum = 0;

            for (auto c : s)
            {
                if (c == '(')
                    ++(sum);
                else
                    --(sum);

                if (sum < 0)
                    ans = true;
            }

            if (sum != 0)
                ans = true;

            if (ans)
                std::cout << "YES\n";
            else
                std::cout << "NO\n";
        }
    }

    return 0;

}
