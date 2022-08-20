/*

 * https://codeforces.com/blog/entry/106049

 * First, the queries are sorted according to the number of rounds.
   After answering the queries in order, they are again sorted according to the
   query numbers (i.e. according to the order in which we are supposed to print
   the answers to the queries).
 * Since a vector of pairs is sorted according to vec[i].first, therefore the
   quantity with respect to which the sorting is to be done is stored in
   vec[i].first.

 */





#include <iostream>
#include <vector>
#include <algorithm>


int main()
{

    std::vector<int> a(100001);
    std::vector<int> victories(100001, 0);

    std::vector<std::pair<int, std::pair<int, int>>> queries(100001);

    int t;
    std::cin >> t;

    while (t--)
    {
        int n, q;
        std::cin >> n >> q;

        std::fill((victories.begin() + 1), (victories.begin() + 1 + n), 0);

        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];

        for (int query_no = 1; query_no <= q; ++(query_no))
        {
            int participant, round_no;
            std::cin >> participant >> round_no;

            participant = a[participant];

            queries[query_no] =
                std::make_pair(round_no, std::make_pair(participant, query_no));
        }

        std::sort((queries.begin() + 1), (queries.begin() + 1 + q));

        int z = 1;

        for (int round_no = 1; round_no < n; ++(round_no))
        {
            if (a[round_no] > a[round_no + 1])
                a[round_no + 1] = a[round_no];
            ++(victories[a[round_no + 1]]);

            while ((z <= q) && (queries[z].first == round_no))
            {
                queries[z].first = queries[z].second.second;
                queries[z].second.second = victories[queries[z].second.first];
                ++z;
            }
        }

        while (z <= q)
        {
            int round_no = queries[z].first;
            queries[z].first = queries[z].second.second;

            if (queries[z].second.first == n)
                queries[z].second.second = (victories[n] + (round_no - n + 1));
            else
                queries[z].second.second = victories[queries[z].second.first];

            ++z;
        }

        std::sort((queries.begin() + 1), (queries.begin() + 1 + q));

        for (int i = 1; i <= q; ++i)
            std::cout << queries[i].second.second << '\n';
    }

    return 0;

}
