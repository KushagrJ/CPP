/*

 * https://codeforces.com/blog/entry/104881

 */





#include <iostream>
#include <vector>


int main()
{

    int test_cases;
    std::cin >> test_cases;

    while ((test_cases)--)
    {
        long long length;
        std::cin >> length;

        int c, q;
        std::cin >> c >> q;

        std::string s;
        std::cin >> s;

        std::vector<long long> a(c);
        std::vector<long long> b(c);
        std::vector<long long> t(c);

        for (int i = 0; i < c; ++i)
        {
            long long l, r;
            std::cin >> l >> r;

            a[i] = (length + 1);
            b[i] = (length + (r - l + 1));
            t[i] = (a[i] - l);

            length += (r - l + 1);
        }

        while (q--)
        {
            long long k;
            std::cin >> k;

            for (int i = (c-1); i >= 0; --i)
            {
                if ((a[i] <= k) && (k <= b[i]))
                    k -= t[i];
            }

            std::cout << s[k-1] << '\n';
        }
    }

    return 0;

}
